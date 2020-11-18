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
#include <chrono>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
/**
 * Initialize a simple log processor.
 * @param exporter the exporter where log records are pushed by this processor
 */
SimpleLogProcessor::SimpleLogProcessor(std::unique_ptr<LogExporter> &&exporter)
    : exporter_(std::move(exporter))
{}

// Batches the log record it receives in a batch of 1 and immediately sends it to the configured exporter  
void SimpleLogProcessor::OnReceive(
    std::unique_ptr<opentelemetry::logs::LogRecord> &&record) noexcept
{
  std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> batch;
  batch.emplace_back(std::move(record));

  // Get lock to ensure Export() is never called concurrently
  std::lock_guard<opentelemetry::common::SpinLockMutex> locked(lock_);

  // Check the ExportCode returned from the export
  if (exporter_->Export(batch) == ExportResult::kFailure)
  {
    /* TODO: alert user of the failed export result */
  }
}
// Forceflush is not used by the simple processor
ProcessorResult SimpleLogProcessor::ForceFlush(std::chrono::microseconds timeout) noexcept {
  // This function and thus return valie is unused 
  return ProcessorResult::kSuccess; 
}

ProcessorResult SimpleLogProcessor::Shutdown(std::chrono::microseconds timeout) noexcept
{
  if(timeout < std::chrono::microseconds(0)){
    // TODO: alert user of invalid parameter? 
    return ProcessorResult::kFailure; 
  }

  auto start_time      = std::chrono::steady_clock::now();

  // While not timed out yet, try to shut down the exporter 
  while(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock ::now() - start_time) < timeout){
    
    // Shutdown should only be called once. 
    if (!shutdown_latch_.test_and_set(std::memory_order_acquire))
    {
      // If exporter finishes shutting down within the timeout, returns the status code of success or failure 
      if (exporter_->Shutdown()){
        return ProcessorResult::kSuccess; 
      } else {
        return ProcessorResult::kFailure; 
      }
    }
  }
  return ProcessorResult::kTimeout; 
  
}
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
