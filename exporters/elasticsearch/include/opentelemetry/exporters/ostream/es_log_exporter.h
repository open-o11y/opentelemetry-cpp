#pragma once

#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/nostd/type_traits.h"
#include "opentelemetry/sdk/logs/exporter.h"

#include "opentelemetry/version.h"

#include <time.h>  // allowed?
#include <iostream>
#include <map>
#include <sstream>
#include "nlohmann/json.hpp"

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;
using json = nlohmann::json;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{
/**
 * The ElasticsearchLogExporter exports logs through an ostream to JSON format
 */
class ElasticsearchLogExporter final : public sdklogs::LogExporter
{
public:
  /**
   * Create an ElasticsearchLogExporter. This constructor takes in a reference to an ostream that the
   * export() function will send log data into.
   * The default ostream is set to stdout
   */
  explicit ElasticsearchLogExporter(std::ostream &sout = std::cout) noexcept;
  sdklogs::ExportResult Export(const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>>
                                   &records) noexcept override;

  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override;

private:
  bool isShutdown_ = false;
  json logs = json::array(); // an empty json array to store all the log records passed to this exporter

};
}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
