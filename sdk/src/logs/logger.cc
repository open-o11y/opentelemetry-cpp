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

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
   Logger::Logger(std::string_view name) noexcept
        : name_{name}, processor_{nullptr}
   {}

   Logger::Logger(std::string_view name, std::shared_ptr<LogProcessor> processor) noexcept
        : name_{name}, processor_{processor}
   {}
   
   std::string_view Logger::GetName() noexcept
   {
       return name_;
   }

   void Logger::log(const opentelemetry::logs::LogRecord &record) noexcept
   {
       //TODO: Sampler
       //If this log's severity is less than the minimum severity, do nothing
       if(!IsEnabled(record.severity))
            return;

        //Inject timestamp
        //TODO: Remove const from record to allow for value injection
        //record.timestamp = core::SystemTimestamp(std::chrono::system_clock::now());


       //Send the log record to our processor
       //Make record a unique_ptr
       auto record_pointer =
       std::unique_ptr<opentelemetry::logs::LogRecord>(new opentelemetry::logs::LogRecord(
          record.timestamp, record.trace_id, record.span_id, record.trace_flag, record.severity,
          record.name, record.body, record.resource, record.attributes));
       GetProcessor()->OnReceive(std::move(record_pointer));
   }

   void Logger::SetMinSeverity(opentelemetry::logs::Severity sev) noexcept
   {
       minSeverity_ = sev;
   }

   bool Logger::IsEnabled(opentelemetry::logs::Severity sev)
   {
       if (sev < minSeverity_)
            return false;
       return true;
   }

   std::shared_ptr<LogProcessor> Logger::GetProcessor() noexcept
   {
       return processor_.load();
   }

   void Logger::SetProcessor(std::shared_ptr<LogProcessor> processor) noexcept
   {
       processor_.store(processor);
   }
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE

