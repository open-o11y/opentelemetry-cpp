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

#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/sdk/logs/logger.h"

#include <gtest/gtest.h>

using namespace opentelemetry::sdk::logs;

TEST(LoggerSDK, SeverityLevelTest)
{
  Logger l;

  // Set the severity to warn
  l.SetMinSeverity(opentelemetry::logs::Severity::kWarn);

  // Anything below kWarn should not be enabled
  ASSERT_FALSE(l.IsEnabled(opentelemetry::logs::Severity::kInfo));

  // Anything above kWarn should be enabled
  ASSERT_TRUE(l.IsEnabled(opentelemetry::logs::Severity::kError));
}

TEST(LoggerSDK, ValueInjection)
{
  // Not currently implemented inside the SDK
  // A future PR will cover this
}
