/*
 * Copyright The OpenTelemetry Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "opentelemetry/sdk/logs/batch_log_processor.h"
#include "opentelemetry/sdk/logs/exporter.h"

#include <gtest/gtest.h>
#include <chrono>
#include <thread>

OPENTELEMETRY_BEGIN_NAMESPACE

using namespace sdk::logs;
using namespace std;
using namespace logs;  // api

/**
 * A class that returns a sample log exporter for testing the batch log processor only
 */
class TestLogExporter final : public LogExporter
{
public:
  TestLogExporter(shared_ptr<vector<unique_ptr<LogRecord>>> logs_received,
                  shared_ptr<atomic<bool>> is_shutdown,
                  shared_ptr<atomic<bool>> is_export_completed,
                  const chrono::milliseconds export_delay = chrono::milliseconds(0))
      : logs_received_(logs_received),
        is_shutdown_(is_shutdown),
        is_export_completed_(is_export_completed),
        export_delay_(export_delay)
  {}

  // Instead of actually exporting the records (as a normal exporter would do),
  // this test exporter's Export method stores the logs received in an internal data struct
  // similar to an InMemory Exporter
  ExportResult Export(const vector<unique_ptr<LogRecord>> &records) noexcept override
  {
    *is_export_completed_ = false;          // Meant exclusively to test force flush timeout
    this_thread::sleep_for(export_delay_);  // give time for the "export" to complete

    // Add the batch of log records to the internal list of records received by this exporter
    for (auto &record : records)
    {
      // Makes a copy of the LogRecord since the original record is a const
      // and thus can't be moved. May change if a Logger can output to
      // multiple processors.
      auto log = unique_ptr<LogRecord>(new LogRecord());
      if (log != nullptr)
      {
        log->name = record->name;
        logs_received_->push_back(move(log));
      }
    }

    *is_export_completed_ = true;
    return ExportResult::kSuccess;
  }

  // Marks this exporter as shut down
  void Shutdown(chrono::microseconds timeout = chrono::microseconds(0)) noexcept override
  {
    *is_shutdown_ = true;
  }

  bool IsExportCompleted() { return is_export_completed_->load(); }

private:
  shared_ptr<vector<unique_ptr<LogRecord>>> logs_received_;
  shared_ptr<atomic<bool>> is_shutdown_;
  shared_ptr<atomic<bool>> is_export_completed_;
  const chrono::milliseconds export_delay_;
};

/**
 * A fixture class for testing the BatchLogProcessor class that uses the TestExporter defined above.
 */
class BatchLogProcessorTest : public ::testing::Test
{
public:
  // Returns a batch log processor that received a batch of log records, a shared pointer to a
  // is_shutdown flag, and the processor configuration options (default if unspecified)
  shared_ptr<LogProcessor> GetTestProcessor(
      shared_ptr<vector<unique_ptr<LogRecord>>> logs_received,
      shared_ptr<atomic<bool>> is_shutdown,
      shared_ptr<atomic<bool>> is_export_completed =
          shared_ptr<atomic<bool>>(new atomic<bool>(false)),
      const chrono::milliseconds export_delay          = chrono::milliseconds(0),
      const chrono::milliseconds schedule_delay_millis = chrono::milliseconds(5000),
      const size_t max_queue_size                      = 2048,
      const size_t max_export_batch_size               = 512)
  {

    return shared_ptr<LogProcessor>(new BatchLogProcessor(
        unique_ptr<LogExporter>(new TestLogExporter(logs_received, is_shutdown, is_export_completed,
                                                    export_delay)),  // test with move later
        max_queue_size, schedule_delay_millis, max_export_batch_size));
  }

  // Returns a vector of LogRecords with names numbered from 1 to num_logs
  shared_ptr<vector<unique_ptr<LogRecord>>> GetTestRecords(const int num_logs)
  {
    shared_ptr<vector<unique_ptr<LogRecord>>> test_logs(new vector<unique_ptr<LogRecord>>);

    for (int i = 0; i < num_logs; i++)
    {
      auto record  = unique_ptr<LogRecord>(new LogRecord());
      record->name = "Log test";
      test_logs->emplace_back(move(record));
      // static_cast<LogRecord *>(test_logs->at(i).get())->name = ("Log test" + to_string(i));
    }

    return test_logs;
  }
};

TEST_F(BatchLogProcessorTest, TestForceFlush)
{
  // Initialize a batch processor

  shared_ptr<atomic<bool>> is_shutdown(new atomic<bool>(false));
  shared_ptr<vector<unique_ptr<LogRecord>>> logs_received(new vector<unique_ptr<LogRecord>>);

  auto batch_processor = GetTestProcessor(logs_received, is_shutdown);

  // Create some log records and send them to the batch processor
  const int num_logs = 2048;
  auto test_logs     = GetTestRecords(num_logs);
  for (int i = 0; i < num_logs; i++)
  {
    batch_processor->OnReceive(move(test_logs->at(i)));
  }

  // Give some time to export the num_logs to the exporter
  this_thread::sleep_for(chrono::milliseconds(50));

  batch_processor->ForceFlush();

  // Check that the logs recieved by the exporter match the logs sent by the batch processor
  EXPECT_EQ(num_logs, logs_received->size());
  for (int i = 0; i < num_logs; i++)
  {
    EXPECT_EQ("Log test", logs_received->at(i)->name);
  }

  // Create some more logs to make sure that the processor still works
  auto more_test_logs = GetTestRecords(num_logs);
  for (int i = 0; i < num_logs; i++)
  {
    batch_processor->OnReceive(move(more_test_logs->at(i)));
  }

  // Give some time to export the additional num_logs logs
  this_thread::sleep_for(chrono::milliseconds(50));

  batch_processor->ForceFlush();

  // Check that the logs recieved by the exporter match the logs sent by the batch processor
  EXPECT_EQ(num_logs * 2, logs_received->size());
  for (int i = 0; i < num_logs; i++)
  {
    EXPECT_EQ("Log test", logs_received->at(num_logs + i)->name);
    // EXPECT_EQ("Log test" + to_string(i % num_logs), logs_received->at(num_logs + i)->name);
  }
}

// When exporting more than max_queue_size logs, some are most likely lost
TEST_F(BatchLogProcessorTest, ExportMaxQueueSizeLogs)
{
  // Create a batch processor with default max_queue_size of 2048
  shared_ptr<atomic<bool>> is_shutdown(new atomic<bool>(false));
  shared_ptr<vector<unique_ptr<LogRecord>>> logs_received(new vector<unique_ptr<LogRecord>>);
  auto batch_processor = GetTestProcessor(logs_received, is_shutdown);

  // Create some test log records and send to batch processor
  const int num_logs = 4096;
  auto test_logs     = GetTestRecords(num_logs);
  for (int i = 0; i < num_logs; i++)
  {
    batch_processor->OnReceive(move(test_logs->at(i)));
  }

  // Give some time to export the logs
  this_thread::sleep_for(chrono::milliseconds(700));
  batch_processor->ForceFlush();

  // Log should be exported by now
  EXPECT_GE(num_logs, logs_received->size());
}

// Test that no logs are lost when sending max_queue_size logs
TEST_F(BatchLogProcessorTest, TestManyLogsLossLess)
{
  // Create a batch processor with a default max_queue_size of 2048
  shared_ptr<atomic<bool>> is_shutdown(new atomic<bool>(false));
  shared_ptr<vector<unique_ptr<LogRecord>>> logs_received(new vector<unique_ptr<LogRecord>>);
  auto batch_processor = GetTestProcessor(logs_received, is_shutdown);

  // Create 2048 numbered sample log records
  const int num_logs = 2048;
  auto test_logs     = GetTestRecords(num_logs);
  for (int i = 0; i < num_logs; i++)
  {
    batch_processor->OnReceive(move(test_logs->at(i)));
  }

  // Give some time to export the logs
  this_thread::sleep_for(chrono::milliseconds(50));

  batch_processor->ForceFlush();

  // Check that the log records sent from processor match log records received by exporter
  EXPECT_EQ(num_logs, logs_received->size());
  for (int i = 0; i < num_logs; i++)
  {
    EXPECT_EQ("Log test", logs_received->at(i)->name);
    // EXPECT_EQ("Log test" + to_string(i), logs_received->at(i)->name);
  }
}

// Test that max_export_batch_size logs are exported every schedule_delay_milliseconds
TEST_F(BatchLogProcessorTest, TestScheduleDelayMillis)
{
  // Create a batch processor wth default max_queue_size of 2048 and default max_export_batch_size
  // of 512
  shared_ptr<atomic<bool>> is_shutdown(new atomic<bool>(false));
  shared_ptr<atomic<bool>> is_export_completed(new atomic<bool>(false));
  shared_ptr<vector<unique_ptr<LogRecord>>> logs_received(new vector<unique_ptr<LogRecord>>);
  const chrono::milliseconds export_delay(0);
  const chrono::milliseconds schedule_delay_millis(2000);

  auto batch_processor = GetTestProcessor(logs_received, is_shutdown, is_export_completed,
                                          export_delay, schedule_delay_millis);

  // Create max_export_batch_size number of sample log records
  const size_t num_logs = 512;  // matches max_export_batch_size of the processor
  auto test_logs        = GetTestRecords(num_logs);

  for (size_t i = 0; i < num_logs; i++)
  {
    batch_processor->OnReceive(move(test_logs->at(i)));
  }

  // Sleep for schedule_delay_millis milliseconds
  this_thread::sleep_for(schedule_delay_millis);

  // Small delay to give time to export
  this_thread::sleep_for(chrono::milliseconds(50));

  // Logs should be exported by now
  // Check that the logs sent by processor match those received by exporter
  EXPECT_TRUE(is_export_completed->load());
  EXPECT_EQ(num_logs, logs_received->size());
  for (size_t i = 0; i < num_logs; i++)
  {
    EXPECT_EQ("Log test", logs_received->at(i)->name);
    // EXPECT_EQ("Log test" + to_string(i), logs_received->at(i)->name);
  }
}

TEST_F(BatchLogProcessorTest, TestShutdown)
{
  // Initialize a batch log processor
  shared_ptr<atomic<bool>> is_shutdown(new atomic<bool>(false));
  shared_ptr<vector<unique_ptr<LogRecord>>> logs_received(new vector<unique_ptr<LogRecord>>);

  auto batch_processor = GetTestProcessor(logs_received, is_shutdown);
  EXPECT_FALSE(is_shutdown->load());

  // Create some test log records and send them to the batch processor
  const int num_logs = 3;
  auto test_logs     = GetTestRecords(num_logs);
  for (int i = 0; i < num_logs; i++)
  {
    batch_processor->OnReceive(move(test_logs->at(i)));
  }

  // test that shutting down the processor will first wait for the current batch of logs to be sent
  // to the log exporter by checking the number of logs sent and the names of the logs sent
  batch_processor->Shutdown();

  EXPECT_EQ(num_logs, logs_received->size());
  for (int i = 0; i < num_logs; i++)
  {
    EXPECT_EQ("Log test", logs_received->at(i)->name);
    // EXPECT_EQ("Log test" + to_string(i), logs_received->at(i)->name);
  }

  // Check that the processor is shut down at the end
  EXPECT_TRUE(is_shutdown->load());
}

OPENTELEMETRY_END_NAMESPACE
