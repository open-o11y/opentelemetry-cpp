#include "opentelemetry/exporters/ostream/log_exporter.h"

#include <iostream>

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{
OStreamLogExporter::OStreamLogExporter(std::ostream &sout) noexcept : sout_(sout) {}

sdklogs::ExportResult OStreamLogExporter::Export(
    const nostd::span<std::shared_ptr<opentelemetry::logs::LogRecord>> &records) noexcept
{
  if (isShutdown_)
  {
    return sdklogs::ExportResult::kFailure;
  }

  for (auto &record : records)
  {
    // Convert trace, spanid, traceflags into string convertable representation
    char trace_id[32] = {0};
    record->trace_id.ToLowerBase16(trace_id);

    char span_id[16] = {0};
    record->span_id.ToLowerBase16(span_id);

    char trace_flags[2] = {0};
    record->trace_flags.ToLowerBase16(trace_flags);

    // Print out each field of the log record

    sout_ << "{\n"
          << "    timestamp   : " << record->timestamp.time_since_epoch().count() << "\n"
          << "    severity    : " << static_cast<int>(record->severity)
          << "\n"
          // << "    severity    : " << severityMap[static_cast<int>(record->severity)] << "\n"
          << "    name        : " << record->name << "\n"
          << "    body        : " << record->body << "\n";

    sout_ << "    resource    : {";
    if (record->resource != nullptr)
    {
      firstKV = true;
      record->resource->ForEachKeyValue([&](nostd::string_view key,
                                            common::AttributeValue value) noexcept {
        printKV(key, value);
        return true;
      });
    }
    sout_ << "}\n";

    sout_ << "    attributes  : {";
    if (record->attributes != nullptr)
    {
      firstKV   = true;
      int count = 0;
      int size  = record->attributes->size();
      record->attributes->ForEachKeyValue([&](nostd::string_view key,
                                              common::AttributeValue value) noexcept {
        printKV(key, value);
        return true;
      });
    }
    sout_ << "}\n";

    sout_ << "    trace_id    : " << std::string(trace_id, 32) << "\n"
          << "    span_id     : " << std::string(span_id, 16) << "\n"
          << "    trace_flags : " << std::string(trace_flags, 2) << "\n"
          << "}\n";
  }

  return sdklogs::ExportResult::kSuccess;
}

bool OStreamLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept
{
  isShutdown_ = true;
  return true;
}

}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
