#pragma once

#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/sdk/logs/logger_provider.h"
#include "opentelemetry/sdk/logs/simple_log_processor.h"

#include "foo_library/foo_library.h"

namespace sdklogs       = opentelemetry::sdk::logs;
namespace logs_api      = opentelemetry::logs;
namespace logs_exporter = opentelemetry::exporter::logs;

// Options for the elasticsearch exporter, with the default being:
//     - Host  = localhost
//     - Port  = 9200
//     - Index = logs
logs_exporter::ElasticsearchExporterOptions options("localhost", 9200, "logs");

void initLogger()
{
  // Create an elasticsearch exporter with given the options
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new logs_exporter::ElasticsearchLogExporter(options));

  // Attach the exporter to a processor
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));

  // Create a loggerprovider and attach the processor
  auto sdkProvider = std::shared_ptr<sdklogs::LoggerProvider>(new sdklogs::LoggerProvider());
  sdkProvider->SetProcessor(processor);
  auto apiProvider = nostd::shared_ptr<logs_api::LoggerProvider>(sdkProvider);

  // Set the global logger providapiProviderer
  logs_api::Provider::SetLoggerProvider(apiProvider);
}

int main(int argc, char *argv[])
{
  // Set the Elasticsearch index from command line arguments
  if (argc > 1)
  {
    options.index_ = argv[1];
  }

  // Setup the logging pipeline
  initLogger();

  foo_library();
}
