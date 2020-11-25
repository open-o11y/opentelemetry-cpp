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

#include "opentelemetry/sdk/logs/logger.h"

#include <gtest/gtest.h>

using namespace opentelemetry::sdk::logs;

TEST(LoggerSDK, LoggerName)
{
  auto lp      = std::shared_ptr<opentelemetry::logs::LoggerProvider>(new LoggerProvider());
  auto logger1 = lp->GetLogger("logger1");
  auto logger2 = lp->GetLogger("logger2");

  ASSERT_EQ("logger1", logger1->GetName());
  ASSERT_EQ("logger2", logger2->GetName());
}

TEST(LoggerSDK, LogToNullProcessor)
{
  // Confirm Logger::log() does not have undefined behavior
  // even when there is no processor set
  // since it calls Processor::OnReceive()

  auto lp     = std::shared_ptr<opentelemetry::logs::LoggerProvider>(new LoggerProvider());
  auto logger = lp->GetLogger("logger");

  // Log a sample log record to a nullptr processor
  auto r  = std::shared_ptr<opentelemetry::logs::LogRecord>(new opentelemetry::logs::LogRecord);
  r->name = "Test log";
  logger->Log(r);
}

class DummyProcessor : public LogProcessor
{
  void OnReceive(std::shared_ptr<opentelemetry::logs::LogRecord> &&record) noexcept {}
  bool ForceFlush(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept
  {
    return true;
  }
  bool Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept
  {
    return true;
  }
};

TEST(LoggerSDK, DefaultValueInjection)
{
  // In order to test value injection, the processor must not be nullptr
  // A DummyProcessor was created above to satisfy this requirement
  std::shared_ptr<LogProcessor> processor = std::shared_ptr<LogProcessor>(new DummyProcessor());
  auto lp                                 = std::shared_ptr<LoggerProvider>(new LoggerProvider());
  lp->SetProcessor(processor);
  auto logger = lp->GetLogger("Logger1");

  // Log a sample log record to the processor
  auto r  = std::shared_ptr<opentelemetry::logs::LogRecord>(new opentelemetry::logs::LogRecord);
  r->name = "Test log";
  logger->Log(r);

  // Check that the log record has injected values

  // Timestamp shouldn't equal 0
  ASSERT_NE(r->timestamp, opentelemetry::core::SystemTimestamp(std::chrono::seconds(0)));

  // TODO: Add checks for traceid, spanid, and traceflags once it gets added
}
