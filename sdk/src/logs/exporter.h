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

#include <memory>
#include <vector>
#include "opentelemetry/logs/log_record.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
/**
 * ExportResult is returned as result of exporting a batch of Log Records.
 */
enum class ExportResult
{
  /**
   * Batch was successfully exported.
   */

  kSuccess = 0,
  /**
   * Exporting failed. The caller must not retry exporting the same batch; the
   * batch must be dropped.
   */
  kFailure
};

/**
 * LogExporter defines the interface that protocol-specific log exporters must
 * implement.
 * /**
 * This LogExporter is the interface that all exporters must implement,
 * that is responsible for conversion of logs to exportable
 * representation and passing them to exporters.
 */

class LogExporter
{
public:
  virtual ~LogExporter() = default;

  /**
   * For each LogRecord in the list of records stored in a vector,
   * format the LogRecord as a (possibly dimensionally altered) LogRecord, then
   * send the LogRecord to the exporter destination. Then returns an ExportResult
   * status error code.
   * The default timeout is set to 0 if unspecified.
   * This method must not be called
   * concurrently for the same exporter instance.
   * @param records: a vector of shared pointers to log records
   */
  virtual ExportResult Export(
      const nostd::span<std::shared_ptr<opentelemetry::logs::LogRecord>>& records) noexcept = 0;

  /**
   * Marks the exporter as ShutDown and cleans up any resources as required.
   * @param timeout: an optional timeout, the default timeout of 0 if unspecified. A timeout of 0
   * means that no timeout is applied.
   */
  virtual void Shutdown(
      std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept = 0;
};
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
