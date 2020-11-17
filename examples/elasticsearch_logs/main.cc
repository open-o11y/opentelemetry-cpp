// Printing logs using a batch processor to ostream (stdout)
#include "opentelemetry/exporters/ostream/log_exporter.h"
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
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new opentelemetry::exporter::logs::ElasticsearchLogExporter());
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));
  // auto provider =
  //     nostd::shared_ptr<logs_api::LoggerProvider>(new sdklogs::LoggerProvider());


  // Set the global logs provider
  // logs_api::Provider::SetLoggerProvider(provider);

  sdklogs::LoggerProvider lp; 
  lp.SetProcessor(processor); 
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
    get_logger()->log("Log ");

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
