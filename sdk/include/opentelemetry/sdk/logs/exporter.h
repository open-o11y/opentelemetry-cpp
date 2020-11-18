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
  // export success - the log was exported successfully
  kSuccess = 0,
  // export failure - if the processor receives this, the log was dropped.
  kFailure 
};

/**
 * LogExporter defines the interface that protocol-specific log exporters must
 * implement.
 */
class LogExporter
{
public:
  virtual ~LogExporter() = default;

  /**
   * Exports a batch of log records.
   * Exporters that implement this should typically format each LogRecord into the format 
   * required by the exporter destination (e.g. JSON), then send the LogRecord to the exporter. 
   * The exporter may retry logs (but the SDK should not). 
   * This method must not block indefinitely. 
   * TODO: Decide on a reasonable upper limit for timeout before returning kFailure. 
   * @param records: a vector of unique pointers to log records
   * @returns an ExportResult status. If this exporter is already shut down, should return kFailure. 
   */
  virtual ExportResult Export(
      const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept = 0;

  /**
   * Marks the exporter as ShutDown and cleans up any resources as required.
   * Shutdown should be called only once for each Exporter instance. 
   * After the call to Shutdown subsequent calls to Export() should immediate return a kFailure result.
   * This method should not block indefinitely. 
   * TODO: The method should decide on a reasonable timeout limit to abort on. 
   * @return true if shutdown succeeded, false otherwise
   */
  virtual bool Shutdown() noexcept = 0;
};
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
