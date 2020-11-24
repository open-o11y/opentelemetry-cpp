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
    const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept
{
  if (isShutdown_)
  {
    return sdklogs::ExportResult::kFailure;
  }

  // print records
  for (auto &record : records)
  {
    if (firstLog)
    {
      firstLog = false;
    }
    else
    {
      sout_ << ",\n";  // comma for previous log record
    }
    // Convert LogRecord to a JSON object
    json log;
    log["timestamp"] =  record->timestamp.time_since_epoch().count();
    log["severity"] =  record->severity;
    log["name"] =  record->name;
    log["body"] =  record->body;
    // log["resource"] =  record->resource;
    // log["attributes"] =  record->attributes;
    // log["trace_id"] =  record->trace_id;
    // log["span_id"] =  record->span_id;
    // log["trace_flag"] =  record->trace_flag;

    // pretty print with indentation of 4 spaces
    sout_ << log.dump(4);
  }

  return sdklogs::ExportResult::kSuccess;
}

void OStreamLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept
{
  sout_ << "\n"; // print newline for final log record

  isShutdown_ = true;
}

}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
