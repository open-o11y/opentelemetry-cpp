
// Sample application
#include "foo_library/foo_library.h"

// Logs (to OStream)
#include "opentelemetry/exporters/ostream/log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/sdk/logs/logger_provider.h"
#include "opentelemetry/sdk/logs/simple_log_processor.h"

// Traces (to Ostream)
#include "opentelemetry/exporters/ostream/span_exporter.h"
#include "opentelemetry/sdk/trace/simple_processor.h"
#include "opentelemetry/sdk/trace/tracer_provider.h"
#include "opentelemetry/trace/provider.h"

namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;

namespace sdktrace  = opentelemetry::sdk::trace;
namespace trace_api = opentelemetry::trace;

namespace
{
void initTracer()
{
  auto exporter = std::unique_ptr<sdktrace::SpanExporter>(
      new opentelemetry::exporter::trace::OStreamSpanExporter);
  auto processor = std::shared_ptr<sdktrace::SpanProcessor>(
      new sdktrace::SimpleSpanProcessor(std::move(exporter)));
  auto provider =
      nostd::shared_ptr<trace_api::TracerProvider>(new sdktrace::TracerProvider(processor));
  // Set the global trace provider
  trace_api::Provider::SetTracerProvider(provider);
}
}  // namespace

namespace
{

void initLogger()
{
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new opentelemetry::exporter::logs::OStreamLogExporter);
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));
  auto sdkProvider = std::shared_ptr<sdklogs::LoggerProvider>(new sdklogs::LoggerProvider());
  sdkProvider->SetProcessor(processor);
  auto apiProvider = nostd::shared_ptr<logs_api::LoggerProvider>(sdkProvider);
  auto provider    = nostd::shared_ptr<logs_api::LoggerProvider>(apiProvider);
  // Set the global logger provider.
  logs_api::Provider::SetLoggerProvider(provider);
}

}  // namespace

int main()
{
  // Removing this line will leave the default noop TracerProvider in place.
  initTracer();

  // Removing this line will leave the default noop LoggerProvider in place.
  initLogger();

  foo_library();
}
