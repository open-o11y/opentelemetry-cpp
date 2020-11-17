// Printing logs using a batch processor to ostream (stdout)
#include "opentelemetry/exporters/ostream/log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/batch_log_processor.h"
#include "opentelemetry/sdk/logs/logger_provider.h"

#include <chrono>
#include <thread>

constexpr int kNumLogs = 10;

namespace
{

void initLogger()
{
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new opentelemetry::exporter::logs::OStreamLogExporter);

  // CONFIGURE BATCH SPAN PROCESSOR PARAMETERS

  // We make the queue size `kNumLogs`*2+5 because when the queue is half full, a preemptive notif
  // is sent to start an export call, which we want to avoid in this simple example.
  const size_t max_queue_size = kNumLogs * 2 + 5;

  // Time interval (in ms) between two consecutive exports.
  const std::chrono::milliseconds schedule_delay_millis = std::chrono::milliseconds(3000);

  // We export `kNumLogs` after every `schedule_delay_millis` milliseconds.
  const size_t max_export_batch_size = kNumLogs;

  auto processor = std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::BatchLogProcessor(
      std::move(exporter), max_queue_size, schedule_delay_millis, max_export_batch_size));

  auto provider = nostd::shared_ptr<opentelemetry::logs::LoggerProvider>(
      new sdklogs::LoggerProvider(processor));
  // Set the global logger provider.
  opentelemetry::logs::Provider::SetLoggerProvider(provider);
}

nostd::shared_ptr<opentelemetry::logs::Logger> get_logger()
{
  auto provider = opentelemetry::logs::Provider::GetLoggerProvider();
  return provider->GetLogger("foo_library");
}

void CreateLogs()
{
  for (int i = 1; i <= kNumLogs; i++)
  {
    get_logger()->log("Log " + std::to_string(i));
  }
}

}  // namespace

int main()
{
  // Removing this line will leave the default noop LoggerProvider in place.
  initLogger();

  std::cout << "Creating first batch of " << kNumLogs << " logs and waiting 3 seconds ...\n";
  CreateLogs();
  std::this_thread::sleep_for(std::chrono::milliseconds(3000 + 50));
  // The logs should now be exported.
  std::cout << "....Exported!\n\n\n";

  // Do the same again
  std::cout << "Creating second batch of " << kNumLogs << " logs and waiting 3 seconds ...\n";
  CreateLogs();
  std::this_thread::sleep_for(std::chrono::milliseconds(3000 + 50));
  std::cout << "....Exported!\n\n\n";

  // Shutdown and drain queue
  CreateLogs();
  printf("Shutting down and draining queue.... \n");
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  // We immediately let the program terminate which invokes the processor destructor
  // which in turn invokes the processor Shutdown(), which finally drains the queue of ALL
  // its logs.
}
