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
 * Struct to hold Elasticsearch exporter options.
 */
struct ElasticsearchExporterOptions
{
  // The host, port, and uri of the Elasticsearch instance which constructs the endpoint
  std::string host_;
  int port_;
  std::string uri_;

  // Constructor defines the default host, port, and uri if the user doesn't specify it
  ElasticsearchExporterOptions(std::string host = "localhost", int port = 9200, std::string uri = "logs/_doc?pretty") : 
      host_{host},
      port_{port},
      uri_{uri}
  {}
};

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
  ElasticsearchLogExporter();

  /**
   * Create an ElasticsearchLogExporter.
   * @param host The host of the Elasticsearch instance
   * @param port The port of the Elasticsearch instance
   */
  ElasticsearchLogExporter(const ElasticsearchExporterOptions &options);
  sdklogs::ExportResult Export(const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>>
                                   &records) noexcept override;

  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds(0)) noexcept override;
private:
  bool isShutdown_ = false;
  json logs = json::array(); // an empty json array to store all the log records passed to this exporter
  
  // Store connection related info with the ElasticsearchExporterOptions class
  ElasticsearchExporterOptions options_;
};
}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
