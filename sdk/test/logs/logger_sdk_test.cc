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
#include "opentelemetry/sdk/trace/tracer_provider.h"
#include "opentelemetry/trace/provider.h"
#include "opentelemetry/exporters/memory/in_memory_span_exporter.h"
#include "opentelemetry/sdk/trace/simple_processor.h"

#include <gtest/gtest.h>

using namespace opentelemetry::sdk::logs;
namespace sdktrace  = opentelemetry::sdk::trace;

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
  opentelemetry::logs::LogRecord r;
  r.name = "Test log";
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
  // TODO: once a Log Exporter is implemented, check that 
  // timestamp, traceid, spanid, and traceflags were 
  // injected from the span context properly
}

