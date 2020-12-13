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

#include "opentelemetry/sdk/common/circular_buffer.h"
#include "opentelemetry/sdk/logs/exporter.h"
#include "opentelemetry/sdk/logs/processor.h"

#include <atomic>
#include <condition_variable>
#include <thread>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{

namespace logs
{

/**
 * This is an implementation of the LogProcessor which creates batches of logs it receives and
 * passes them to the configured LogExporter.
 */
class BatchLogProcessor : public LogProcessor
{
public:
  /**
   * Creates a batch log processor by configuring the specified exporter and other parameters
   * as per the official, language-agnostic opentelemetry specs.
   *
   * @param exporter - The backend exporter to pass the ended logs to
   * @param max_queue_size -  The maximum buffer/queue size. After the size is reached, logs are
   * dropped.
   * @param schedule_delay_millis - The time interval between two consecutive exports.
   * @param max_export_batch_size - The maximum batch size of every export. It must be smaller or
   * equal to max_queue_size
   */
  explicit BatchLogProcessor(
      std::unique_ptr<LogExporter> &&exporter,
      const size_t max_queue_size                           = 2048,
      const std::chrono::milliseconds schedule_delay_millis = std::chrono::milliseconds(5000),
      const size_t max_export_batch_size                    = 512);

  /**
   * Called when the Logger's log method is called.
   * @param record - The log that was just received from the Logger
   */

  void OnReceive(std::unique_ptr<opentelemetry::logs::LogRecord> &&record) noexcept override;

  /**
   * Completely drains the buffer/queue of
   * all its ended logs and passes them to the exporter.
   * NOTE: Timeout functionality not supported yet.
   */
  void ForceFlush(
      std::chrono::microseconds timeout = std::chrono::milliseconds(0)) noexcept override;

  /**
   * Shuts down the processor and does any cleanup required.
   * Any subsequent calls to OnReceive, ForceFlush or Shutdown
   * will return immediately without doing anything.
   * NOTE: Timeout functionality not supported yet.
   */
  void Shutdown(std::chrono::microseconds timeout = std::chrono::milliseconds(0)) noexcept override;

  /**
   * The Shutdown() method is supposed to be invoked by this class destructor
   * (as per other languages), but the C++ Logger has shared ownership
   * of the processor with other Loggers so the processor will not be shutdown.
   */
  ~BatchLogProcessor();

private:
  /* The background routine performed by the worker thread. */
  void DoBackgroundWork();

  /**
   * Exports all ended logs to the configured exporter.
   *
   * @param was_force_flush_called - A flag to check if the current export is the result
   *                                 of a call to ForceFlush method. If true, then we have to
   *                                 notify the main thread to wake it up in the ForceFlush
   *                                 method.
   */
  void Export(const bool was_for_flush_called);

  /**
   * Called when Shutdown() is invoked. Completely drains the queue of all log records and
   * passes them to the exporter.
   */
  void DrainQueue();

  /* The configured backend log exporter */
  std::unique_ptr<LogExporter> exporter_;

  /* Configurable parameters as per the tracing spec */
  const size_t max_queue_size_;
  const std::chrono::milliseconds schedule_delay_millis_;
  const size_t max_export_batch_size_;

  /* Synchronization primitives */
  std::condition_variable cv_, force_flush_cv_;
  std::mutex cv_m_, force_flush_cv_m_;

  /* The buffer/queue to which the ended logs are added */
  common::CircularBuffer<opentelemetry::logs::LogRecord> buffer_;

  /* Important boolean flags to handle the workflow of the processor */
  std::atomic<bool> is_shutdown_{false};
  std::atomic<bool> is_force_flush_{false};
  std::atomic<bool> is_force_flush_notified_{false};

  /* The background worker thread */
  std::thread worker_thread_;
};

}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
