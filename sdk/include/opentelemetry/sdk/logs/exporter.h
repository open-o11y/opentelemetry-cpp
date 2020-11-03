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
  kSuccess = 0,
  // If exporting failed, the caller can not retry exporting the same batch, so the logs must be
  // dropped.
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
   * Format each LogRecord as a (possibly dimensionally altered) LogRecord, then
   * send the LogRecord to the exporter destination.
   *
   * The default timeout is set to 0 if unspecified.
   * @param records: a vector of unique pointers to log records
   * @returns an ExportResult status
   */
  virtual ExportResult Export(
      const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept = 0;

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
