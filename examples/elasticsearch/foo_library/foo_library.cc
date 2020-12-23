#include "opentelemetry/logs/provider.h"

namespace nostd = opentelemetry::nostd;

namespace
{
nostd::shared_ptr<opentelemetry::logs::Logger> get_logger()
{
  auto provider = opentelemetry::logs::Provider::GetLoggerProvider();
  return provider->GetLogger("foo_library");
}
}  // namespace

void foo_library()
{
  auto logger = get_logger();

  // Log a basic message
  logger->Log(opentelemetry::logs::Severity::kInfo, "Basic log message");

  // Log with the 6 different severity overloads
  logger->Trace("Trace message");
  logger->Debug("Debug log", "Debug message");
  logger->Info({{"key1", "attribute1"}, {"key2", "attribute2"}});
  logger->Warn("Warn log", {{"key1", "attribute1"}, {"key2", "attribute2"}});
  std::map<std::string, int> map_ = {{"key1_map", 4}, {"key2_map", 7}};
  logger->Error(map_);
  std::vector<std::pair<std::string, float>> vec_ = {{"key1_vec", 3.14}, {"key2_vec", 2.72}};
  logger->Fatal("Fatal vector log", vec_);

  // Log all the Log Data Model fields
  auto now = std::chrono::system_clock::now();
  auto trace_id = opentelemetry::trace::TraceId();
  auto span_id = opentelemetry::trace::SpanId();
  auto trace_flags = opentelemetry::trace::TraceFlags();
  logger->Log(opentelemetry::logs::Severity::kInfo, "Name", "Body", {{"Key", "Resources"}}, 
              {{"Key", "Attributes"}}, trace_id, span_id, trace_flags, now);
}
