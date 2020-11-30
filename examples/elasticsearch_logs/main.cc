// Printing logs using a batch processor to ostream (stdout)
#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/sdk/logs/simple_log_processor.h"
#include "opentelemetry/sdk/logs/logger_provider.h"


namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;


namespace
{

void initLogger()
{
  auto ES_exporter = new opentelemetry::exporter::logs::ElasticsearchLogExporter("localhost", 3000);
  ES_exporter->SetURI("users");
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(ES_exporter);
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));
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
    get_logger()->log("Log");

    // get_logger()->log("Log " + std::to_string(i));
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
