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
  logger->log(r);
}
