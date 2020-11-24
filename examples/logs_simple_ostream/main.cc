// Using an exporter that simply prints logs to stdout.

#include "foo_library/foo_library.h"
#include "opentelemetry/exporters/ostream/log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/sdk/logs/logger_provider.h"
#include "opentelemetry/sdk/logs/simple_log_processor.h"

#include <iostream>

namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;

namespace
{

void initLogger()
{
  auto exporter = std::unique_ptr<sdklogs::LogExporter>(new opentelemetry::exporter::logs::OStreamLogExporter);
  auto processor = std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));
  auto sdkProvider = std::shared_ptr<sdklogs::LoggerProvider>(new sdklogs::LoggerProvider());
  sdkProvider->SetProcessor(processor);
  auto apiProvider = nostd::shared_ptr<logs_api::LoggerProvider>(sdkProvider);
  auto provider = nostd::shared_ptr<logs_api::LoggerProvider>(apiProvider);
  // Set the global logger provider.
  logs_api::Provider::SetLoggerProvider(provider);
}

}  // namespace

int main()
{
  // Removing this line will leave the default noop LoggerProvider in place.
  initLogger();

  foo_library();
}
