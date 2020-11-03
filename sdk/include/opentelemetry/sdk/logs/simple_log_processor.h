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

#include <atomic>
#include <mutex>

#include "opentelemetry/common/spin_lock_mutex.h"
#include "opentelemetry/sdk/logs/exporter.h"
#include "opentelemetry/sdk/logs/processor.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
/**
 * The simple log processor passes all log records
 * as soon as they are received to the configured
 * LogExporter.
 *
 * All calls to the configured LogExporter are synchronized using a
 * spin-lock on an atomic_flag.
 */
class SimpleLogProcessor : public LogProcessor
{

public:
  /**
   * Initialize a simple log processor.
   * @param exporter the exporter used by the log processor
   */
  // Constructor and destructor
  explicit SimpleLogProcessor(std::unique_ptr<LogExporter> &&exporter);
  virtual ~SimpleLogProcessor() = default;

  // Overloaded methods from base LogProcessor class
  void OnReceive(std::unique_ptr<opentelemetry::logs::LogRecord> &&record) noexcept override;
  void ForceFlush(
      std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override;
  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override;

private:
  std::unique_ptr<LogExporter> exporter_;
  opentelemetry::common::SpinLockMutex lock_;
  std::atomic_flag shutdown_latch_{ATOMIC_FLAG_INIT};
};
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
