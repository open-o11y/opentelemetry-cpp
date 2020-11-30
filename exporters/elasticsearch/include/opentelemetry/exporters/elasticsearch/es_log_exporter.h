#pragma once

#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/nostd/type_traits.h"
#include "opentelemetry/sdk/logs/exporter.h"
#include "opentelemetry/ext//http/client/curl//http_client_curl.h"

#include "opentelemetry/version.h"

#include <time.h>  // allowed?
#include <iostream>
#include <map>
#include <sstream>
#include "opentelemetry/exporters/elasticsearch/json.hpp"

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
   * Create an ElasticsearchLogExporter.
   * Specifies the host and port to localhost:9200s by defaults
   */
  explicit ElasticsearchLogExporter() noexcept;

  /**
   * Create an ElasticsearchLogExporter.
   * @param host The host of the Elasticsearch instance
   * @param port The port of the Elasticsearch instance
   */
  explicit ElasticsearchLogExporter(std::string_view host, int port) noexcept;
  sdklogs::ExportResult Export(const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>>
                                   &records) noexcept override;

  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override;

  /**
   * Sets the URI for the http requests.
   */
  void SetURI(std::string_view uri) noexcept;

  /**
   * Sets the API key for the Elasticsearch instance.
   */
  void SetAPIKey(std::string_view key) noexcept;
private:
  bool isShutdown_ = false;
  json logs = json::array(); // an empty json array to store all the log records passed to this exporter
  
  // Store http related information
  std::string_view host_;
  int port_;
  std::string_view uri_;
};
}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
