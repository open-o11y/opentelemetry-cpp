// Printing logs using a batch processor to ostream (stdout)
#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/sdk/logs/batch_log_processor.h"
#include "opentelemetry/sdk/logs/logger_provider.h"


namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;
namespace logs_exporter = opentelemetry::exporter::logs;


namespace
{

void initLogger()
{
  logs_exporter::ElasticsearchExporterOptions options("localhost", 9200, "logs");
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new logs_exporter::ElasticsearchLogExporter(options));
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::BatchLogProcessor(std::move(exporter)));
  auto sdkProvider = std::shared_ptr<sdklogs::LoggerProvider>(new sdklogs::LoggerProvider());
  sdkProvider->SetProcessor(processor);
  auto apiProvider = nostd::shared_ptr<opentelemetry::logs::LoggerProvider>(sdkProvider);
  auto provider = nostd::shared_ptr<opentelemetry::logs::LoggerProvider>(apiProvider);
  
  // Set the global logger provider.
  opentelemetry::logs::Provider::SetLoggerProvider(provider);
}

nostd::shared_ptr<opentelemetry::logs::Logger> get_logger()
{
  auto provider = opentelemetry::logs::Provider::GetLoggerProvider();
  return provider->GetLogger("logger");
}

void CreateLogs(const int kNumLogs)
{
  for (int i = 1; i <= kNumLogs; i++)
  {
    get_logger()->log("Log hello");
    //get_logger()->log("Log " + std::to_string(i));
  }
}
}  // namespace

int main()
{
  // Removing this line will leave the default noop LoggerProvider in place.
  initLogger();
  

  // Send kNumLogs to exporter
  const int kNumLogs = 5; 
  CreateLogs(kNumLogs);
}
