#pragma once

#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/nostd/type_traits.h"
#include "opentelemetry/sdk/logs/exporter.h"

#include "opentelemetry/version.h"

#include <time.h>  // allowed?
#include <iostream>
#include <map>
#include <sstream>

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{
/**
 * The OStreamSpanExporter exports logs through an ostream to JSON format
 */
class OStreamLogExporter final : public sdklogs::LogExporter
{
public:
  /**
   * Create an OStreamLogExporter. This constructor takes in a reference to an ostream that the
   * export() function will send log data into.
   * The default ostream is set to stdout
   */
  explicit OStreamLogExporter(std::ostream &sout = std::cout) noexcept;
  sdklogs::ExportResult Export(const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>>
                                   &records) noexcept override;

  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override;

private:
  std::ostream &sout_;
  bool isShutdown_ = false;
  bool firstLog    = true;
  /*!
   From:
   https://github.com/nlohmann/json/blob/ec7a1d834773f9fee90d8ae908a0c9933c5646fc/src/json.hpp#L4604-L4697
   Can use a dependency on this library?
   */

  void printBody(const nostd::string_view &body)
  {
    // TODO
    sout_ << "\"" << body << "\"";
  }

  void printKVI(const common::KeyValueIterable &attr)
  {
    sout_ << "[";
    
    
    sout_ << "]";
  }

  void printRecord(const std::unique_ptr<opentelemetry::logs::LogRecord> &record)
  {
    if (firstLog)
    {
      sout_ << "[";
      firstLog = false;
    }
    else
    {
      sout_ << ",";  // comma for previous log record
    }
    
    sout_ << "\n   {"
          << "\n      \"timestamp\"     : " << record->timestamp.time_since_epoch().count() << ","
          << "\n      \"severity\"      : " << record->severityToString(record->severity) << ","
          << "\n      \"name\"          : "
          << "\"" << record->name << "\","  // TODO: convert the name field from string_view to a
                                            // string so it can be sent to the escape_string method
          << "\n      \"body\"          : ";
    printBody(record->body);  // TODO: convert the body field from string_view to a string so it can
                              // be sent to the escape_string method
    sout_ << ",";
    sout_ << "\n      \"resource\"      : ";
    printKVI(record->resource);
    sout_ << ",";
    sout_ << "\n      \"attributes\"    : ";
    printKVI(record->attributes);
    sout_ << ",";
    sout_ << "\n      \"trace_id\"      : "
          << "[]" /*std::string(record->trace_id, 32)*/ << ","
          << "\n      \"span_id\"       : "
          << "[]" /*std::string(record->span_id, 16)*/ << ","
          << "\n      \"trace_flags\"   : "
          << "[]" /*record->trace_flags*/ << ",";

    sout_ << "\n   }";  // end of log record
  }
};
}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE