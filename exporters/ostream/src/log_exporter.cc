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
  for (auto &r : records)
  {
    printRecord(r);
  }

  return sdklogs::ExportResult::kSuccess;
}

void OStreamLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept
{
  isShutdown_ = true;

  sout_ << "]\n";
}

}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
