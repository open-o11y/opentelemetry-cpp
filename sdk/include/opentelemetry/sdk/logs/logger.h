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

#pragma once

#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/logs/logger.h"
#include "opentelemetry/nostd/shared_ptr.h"
#include "opentelemetry/nostd/string_view.h"
#include "opentelemetry/sdk/common/atomic_shared_ptr.h"
#include "opentelemetry/sdk/logs/processor.h"

#include <unordered_set>
#include <vector>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
class Logger final : public opentelemetry::logs::Logger, public std::enable_shared_from_this<Logger>
{
public:
  /**
   * Initialize a new logger with a specified name.
   * @param name The name of this logger.
   */
  explicit Logger(std::string name) noexcept;

  /**
   * Initialize a new logger with a specified name and processor.
   * @param name The name of this logger.
   * @param processor The name of the processor.
   */
  explicit Logger(std::string name, std::shared_ptr<LogProcessor> processor) noexcept;

  /**
   * Get the name of this Logger.
   */
  std::string GetName() noexcept;

  /**
   * Writes a log record into the processor. The log record will only be
   * sent if the severity level is greater than the minimum severity set by
   * SetMinSeverity(s).
   * @param record The record to write into the processor.
   */
  void log(const opentelemetry::logs::LogRecord &record) noexcept override;

  /**
   * Sets the minimum severity of a log in order to be sent to the
   * processor.
   * @param sev The minimum severity
   */
  void SetMinSeverity(opentelemetry::logs::Severity sev) noexcept;

  /**
   * Returns whether a severity level is enabled or not.
   * @param sev The severity level to be checked
   */
  bool IsEnabled(opentelemetry::logs::Severity sev);

  /**
   * Returns a shared pointer to the processor currently stored in the
   * logger provider. If no processor exists, returns a nullptr
   */
  std::shared_ptr<LogProcessor> GetProcessor() noexcept;

  // Sets the common processor that all the Logger instances will use
  /**
   * Sets the processor that is stored internally in the logger provider.
   * @param processor The processor to be stored inside the logger provider.
   * This must not be a nullptr.
   */
  void SetProcessor(std::shared_ptr<LogProcessor> processor) noexcept;

private:
  // The name of this Logger
  std::string name_;

  // The minimum severity of this Logger
  opentelemetry::logs::Severity minSeverity_;

  // The processor of this Logger
  sdk::AtomicSharedPtr<LogProcessor> processor_;
};

}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
