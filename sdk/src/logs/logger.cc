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
Logger::Logger(opentelemetry::nostd::string_view name,
               std::shared_ptr<LoggerProvider> logger_provider) noexcept
    : logger_name_(name), logger_provider_(logger_provider)
{}

opentelemetry::nostd::string_view Logger::GetName() noexcept
{
  return logger_name_;
}

void Logger::Log(opentelemetry::nostd::shared_ptr<opentelemetry::logs::LogRecord> record) noexcept
{
  // If this logger does not have a processor, no need to create a log record
  auto processor = logger_provider_.lock()->GetProcessor();
  if (processor == nullptr)
  {
    return;
  }

  // TODO: Sampler logic (should include check for minSeverity)

  // Inject values into record if not user specified
  // Timestamp
  if (record->timestamp == opentelemetry::core::SystemTimestamp(std::chrono::seconds(0)))
    record->timestamp = core::SystemTimestamp(std::chrono::system_clock::now());

  // Traceid
  char trace_buf[32];
  record->trace_id.ToLowerBase16(trace_buf);
  if (std::string(trace_buf, sizeof(trace_buf)), "00000000000000000000000000000000")
  { 
    //TODO
  }

  // Spanid
  char span_buf[16];
  record->span_id.ToLowerBase16(span_buf);
  if (std::string(span_buf, sizeof(span_buf)), "0000000000000000")
  { 
    //TODO
  }

  // Traceflag
  char flag_buf[2];
  record->trace_flag.ToLowerBase16(flag_buf);
  if (std::string(flag_buf, sizeof(flag_buf)), "00")
  { 
    //TODO
  }
  
  // Inject logger name into record
  
  // TODO: inject traceid/spanid later

  // Send the log record to the processor
  processor->OnReceive(record);
}

}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
