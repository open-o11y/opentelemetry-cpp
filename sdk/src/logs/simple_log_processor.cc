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

#include "opentelemetry/sdk/logs/simple_log_processor.h"

#include <vector>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
SimpleLogProcessor::SimpleLogProcessor(std::unique_ptr<LogExporter> &&exporter)
    : exporter_(std::move(exporter))
{}

void SimpleLogProcessor::OnReceive(
    std::unique_ptr<opentelemetry::logs::LogRecord> &&record) noexcept
{
  std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> batch;
  batch.emplace_back(std::move(record));

  // get lock to ensure while Export() is never called concurrently
  std::lock_guard<opentelemetry::common::SpinLockMutex> locked(lock_);

  // check the ExportCode returned from the export
  if (exporter_->Export(batch) == ExportResult::kFailure)
  {
    /* TODO: throw exception? */
  }
}

// overloaded ForceFlush() method does nothing in simple processor
void SimpleLogProcessor::ForceFlush(std::chrono::microseconds timeout) noexcept {}

void SimpleLogProcessor::Shutdown(std::chrono::microseconds timeout) noexcept
{
  // ensures exporter's ShutDown() method is only called once
  if (!shutdown_latch_.test_and_set(std::memory_order_acquire))
  {
    exporter_->Shutdown(timeout);
  }
}
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
