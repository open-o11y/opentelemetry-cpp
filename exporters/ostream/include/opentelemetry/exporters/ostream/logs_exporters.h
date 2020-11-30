#pragma once

// #include "nlohmann/json.hpp"
#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/nostd/type_traits.h"
#include "opentelemetry/sdk/logs/exporter.h"
#include "opentelemetry/version.h"  // needed?

#include <iostream>
#include <map>
#include <sstream>

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;
// using json = nlohmann::json;
// using ordered_json = nlohmann::ordered_json; // should be working with PR
// https://github.com/nlohmann/json/pull/2258

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{
/**
 * The OStreamLogExporter exports logs through an ostream to JSON format
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
};
}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
