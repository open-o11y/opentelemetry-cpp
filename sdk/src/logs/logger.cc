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
#include "opentelemetry/trace/provider.h"
#include "opentelemetry/sdk/trace/span_data.h"

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

void Logger::Log(opentelemetry::logs::LogRecord &record) noexcept
{
  // If this logger does not have a processor, no need to create a log record
  auto processor = logger_provider_.lock()->GetProcessor();
  if (processor == nullptr)
  {
    return;
  }

  // TODO: Sampler logic (should include check for minSeverity)

  // Create a shared pointer to the LogRecord to be passed to the processor(s)
  auto r = opentelemetry::nostd::shared_ptr<opentelemetry::logs::LogRecord>(new opentelemetry::logs::LogRecord(record));

  // Inject values into record if not user specified
  // Timestamp
  if (r->timestamp == opentelemetry::core::SystemTimestamp(std::chrono::seconds(0)))
  {
    r->timestamp = core::SystemTimestamp(std::chrono::system_clock::now());
  }

  auto provider = opentelemetry::trace::Provider::GetTracerProvider();
  auto tracer = provider->GetTracer("foo_library");
  auto span_context = tracer->GetCurrentSpan()->GetContext();
  
  // Traceid
  if (!r->trace_id.IsValid())
  {
     r->trace_id = span_context.trace_id();
  }

  // Spanid
  if (!r->span_id.IsValid())
  {
    r->span_id = span_context.span_id(); 
  }

  // Traceflag
  if (!r->trace_flags.IsSampled())
  {
    r->trace_flags = span_context.trace_flags();
  }

  // TODO: Inject logger name into record

  // Send the log record to the processor
  processor->OnReceive(r);
}

}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
