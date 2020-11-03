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

#include "opentelemetry/sdk/logs/logger_provider.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/nostd/shared_ptr.h"

#include <gtest/gtest.h>

using namespace opentelemetry::sdk::logs;

TEST(LoggerProviderSDK, PushToAPI)
{
    auto lp = opentelemetry::nostd::shared_ptr<opentelemetry::logs::LoggerProvider>(new opentelemetry::sdk::logs::LoggerProvider());
    opentelemetry::logs::Provider::SetLoggerProvider(lp);

    //Check that the loggerprovider was correctly pushed into the API
    ASSERT_EQ(lp, opentelemetry::logs::Provider::GetLoggerProvider());
}

TEST(LoggerProviderSDK, LoggerProviderGetLogger)
{
    LoggerProvider lp;

    auto logger1 = lp.GetLogger("logger1");
    auto logger2 = lp.GetLogger("logger2");

    //Check that the logger is not nullptr
    ASSERT_NE(logger1, nullptr);

    //Check that two loggers with different names aren't the same instance
    ASSERT_NE(logger1, logger2);

    //Create a logger with the same name as another, check they are the same
    auto logger3 = lp.GetLogger("logger1");
    ASSERT_EQ(logger1, logger3);
}

class DummyProcessor : public LogProcessor
{
  void OnReceive(std::unique_ptr<opentelemetry::logs::LogRecord> &&record) noexcept
  {}

  void ForceFlush(
      std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept
  {}

  void Shutdown(
      std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept
  {}
};

TEST(LoggerProviderSDK, LoggerProviderProcessor)
{
    LoggerProvider lp;

    //Check that initially the processor is null
    ASSERT_EQ(lp.GetProcessor(), nullptr);

    //Create a new processor and check if it is pushed correctly
    std::shared_ptr<LogProcessor> proc = std::shared_ptr<LogProcessor>(new DummyProcessor());
    lp.SetProcessor(proc);
    ASSERT_EQ(proc, lp.GetProcessor());
}

