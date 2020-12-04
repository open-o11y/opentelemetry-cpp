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
#include "opentelemetry/sdk/trace/span_data.h"
#include "opentelemetry/trace/provider.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
Logger::Logger(std::shared_ptr<LoggerProvider> logger_provider) noexcept
    : logger_provider_(logger_provider)
{}

void Logger::log(const opentelemetry::logs::LogRecord &record) noexcept
{
  // If this logger does not have a processor, no need to create a log record
  auto processor = logger_provider_.lock()->GetProcessor();
  if (processor == nullptr)
  {
    return;
  }

  // TODO: Sampler logic (should include check for minSeverity)

  // Create a shared pointer to the LogRecord to be passed to the processor(s)
  auto record_pointer =
      std::shared_ptr<opentelemetry::logs::LogRecord>(new opentelemetry::logs::LogRecord(record));

  // Inject values into record if not user specified
  // Timestamp
  if (record_pointer->timestamp == opentelemetry::core::SystemTimestamp(std::chrono::seconds(0)))
  {
    record_pointer->timestamp = core::SystemTimestamp(std::chrono::system_clock::now());
  }

  auto provider     = opentelemetry::trace::Provider::GetTracerProvider();
  auto tracer       = provider->GetTracer("foo_library");
  auto span_context = tracer->GetCurrentSpan()->GetContext();

  // Traceid
  if (!record_pointer->trace_id.IsValid())
  {
    record_pointer->trace_id = span_context.trace_id();
  }

  // Spanid
  if (!record_pointer->span_id.IsValid())
  {
    record_pointer->span_id = span_context.span_id();
  }

  // Traceflag
  if (!record_pointer->trace_flag.IsSampled())
  {
    record_pointer->trace_flag = span_context.trace_flags();
  }

  // TODO: Inject logger name into record

  // Send the log record to the processor
  processor->OnReceive(record_pointer);
}

}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
