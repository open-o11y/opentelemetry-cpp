#include "opentelemetry/sdk/logs/simple_log_processor.h"
#include <gtest/gtest.h>

using namespace opentelemetry::sdk::logs;
using opentelemetry::logs::LogRecord;

/*
 * A test exporter used to record (and give back) the # of times Shutdown was called,
 * and that can return a vector of all the records it has received.
 */
class TestExporter final : public LogExporter
{
public:
  TestExporter(int *shutdown_counter,
               std::shared_ptr<std::vector<std::unique_ptr<LogRecord>>> logs_received,
               int *batch_size_received)
      : shutdown_counter_(shutdown_counter),
        logs_received_(logs_received),
        batch_size_received(batch_size_received)
  {}

  ExportResult Export(const std::vector<std::unique_ptr<LogRecord>> &records) noexcept override
  {
    *batch_size_received = records.size();
    // Add the batch of log records to the internal list of records received by this exporter
    for (auto &record : records)
    {
      // Create a copy of the record in the records_received_ vector
      auto log = std::unique_ptr<LogRecord>(new LogRecord());
      if (log != nullptr)
      {
        // Just copies over the name of log record set (not any of the other fields)
        log->name = record->name;
        logs_received_->emplace_back(std::move(log));
      }
    }
    return ExportResult::kSuccess;
  }

  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override
  {
    *shutdown_counter_ += 1;
  }
  // New method to return the list of all the records this exporter has received
  std::shared_ptr<std::vector<std::unique_ptr<LogRecord>>> GetRecordsReceived()
  {
    return logs_received_;
  }

private:
  int *shutdown_counter_;
  std::shared_ptr<std::vector<std::unique_ptr<LogRecord>>> logs_received_;
  int *batch_size_received;
};

TEST(SimpleLogProcessorTest, SendReceivedLogsToExporter)
{
  /** Tests whether the simple processor successfully creates a batch of size 1
   * and whether the contents of the record is sent to the exporter properly without modification
   */

  int shutdown_counter = 0;

  std::shared_ptr<std::vector<std::unique_ptr<LogRecord>>> logs_received(
      new std::vector<std::unique_ptr<LogRecord>>);

  int batch_size_received = 0;

  std::unique_ptr<TestExporter> exporter(
      new TestExporter(&shutdown_counter, logs_received, &batch_size_received));
  SimpleLogProcessor processor(std::move(exporter));

  // Create some sample log records to send to exporter
  const int num_logs = 5;
  for (int i = 0; i < num_logs; i++)
  {
    auto record  = std::unique_ptr<LogRecord>(new LogRecord());
    record->name = "Log name" + std::to_string(i);

    // Call processor with the log record (which should send log record to exporter)
    processor.OnReceive(std::move(record));

    // Simple processor should always send log records in a vector of size 1 to exporter
    ASSERT_EQ(1, batch_size_received);
  }

  // Test whether the processor's log sent matches the log record received by the exporter
  ASSERT_EQ(logs_received->size(), num_logs);
  for (int i = 0; i < num_logs; i++)
  {
    ASSERT_EQ("Log name" + std::to_string(i), (*(logs_received->data() + i))->name);
  }
}

// Tests behavior when calling the processor's ShutDown() multiple times
TEST(SimpleLogProcessorTest, ShutdownCalledOnce)
{
  // Create a TestShutDownExporter that increments num_shutdowns everytime LogExporter::ShutDown()
  // is called
  int num_shutdowns = 0;

  std::shared_ptr<std::vector<std::unique_ptr<LogRecord>>> logs_received(
      new std::vector<std::unique_ptr<LogRecord>>);

  int batch_size_received = 0;

  std::unique_ptr<TestExporter> exporter(
      new TestExporter(&num_shutdowns, logs_received, &batch_size_received));

  // Call Processor::ShutDown() and check that the exporter is shutdown at most once
  // (i.e. at most 1 num_shutdowns)
  SimpleLogProcessor processor(std::move(exporter));

  EXPECT_EQ(0, num_shutdowns);  // Initial value
  processor.Shutdown();
  EXPECT_EQ(1, num_shutdowns);
  processor.Shutdown();
  EXPECT_EQ(1, num_shutdowns);  // Should still be 1, even though ShutDown() has been called twice.
}
