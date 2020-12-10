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
 #include "opentelemetry/sdk/logs/log_record.h"
 #include "opentelemetry/trace/provider.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
Logger::Logger(std::shared_ptr<LoggerProvider> logger_provider) noexcept
    : logger_provider_(logger_provider)
{}

/**
 * Create and popualte recordable with the log event's fields passed in. 
 * The timestamp, severity, traceid, spanid, and traceflags, are injected
 * if the user does not specify them.
 */ 
void Logger::Log(core::SystemTimestamp timestamp, opentelemetry::logs::Severity severity,  nostd::string_view name, nostd::string_view body, const common::KeyValueIterable &resource, const common::KeyValueIterable &attributes, opentelemetry::trace::TraceId trace_id, opentelemetry::trace::SpanId span_id, opentelemetry::trace::TraceFlags trace_flags) noexcept
{
  // If this logger does not have a processor, no need to create a log record
  auto processor = logger_provider_.lock()->GetProcessor();
  if (processor == nullptr)
  {
    return;
  }

  // TODO: Sampler logic (should include check for minSeverity)

  auto recordable = processor->MakeRecordable();
  if (recordable == nullptr)
  {
    return;
  }

  // Populate recordable fields
  if (timestamp == this->default_timestamp_){
    // Inject current timestamp if none is specified by user 
    recordable->SetTimestamp(core::SystemTimestamp(std::chrono::system_clock::now()));
  } 
  else 
  {
    recordable->SetTimestamp(timestamp);
  }

  recordable->SetSeverity(severity);
  recordable->SetName(name);
  recordable->SetBody(body);

  resource.ForEachKeyValue([&](nostd::string_view key,
                               opentelemetry::common::AttributeValue value) noexcept {
    recordable->SetResource(key, value);
    return true;
  });

  attributes.ForEachKeyValue([&](nostd::string_view key,
                                 opentelemetry::common::AttributeValue value) noexcept {
    recordable->SetAttribute(key, value);
    return true;
  });


  // Inject trace_id/span_id/trace_flags if none is set by user
  auto provider     = opentelemetry::trace::Provider::GetTracerProvider();
  auto tracer       = provider->GetTracer("foo_library");
  auto span_context = tracer->GetCurrentSpan()->GetContext();

  // Traceid
  if (!trace_id.IsValid())
  {
    recordable->SetTraceId(span_context.trace_id());
  } 
  else 
  {
    recordable->SetTraceId(trace_id);
  }

  // Spanid
  if (!span_id.IsValid())
  {
    recordable->SetSpanId(span_context.span_id());
  } 
  else 
  {
    recordable->SetSpanId(span_id);
  }

  // Traceflag
  if (!trace_flags.IsSampled())
  {
    recordable->SetTraceFlags(span_context.trace_flags());
  } 
  else 
  {
    recordable->SetTraceFlags(trace_flags);
  }

  // Send the log record to the processor
  processor->OnReceive(std::move(recordable));
}

}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
