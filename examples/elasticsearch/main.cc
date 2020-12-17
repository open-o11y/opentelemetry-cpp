#pragma once

#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/sdk/logs/simple_log_processor.h"
#include "opentelemetry/sdk/logs/logger_provider.h"
#include "opentelemetry/sdk/trace/simple_processor.h"
#include "opentelemetry/sdk/trace/tracer_provider.h"
#include "opentelemetry/trace/provider.h"
#include "opentelemetry/exporters/memory/in_memory_span_exporter.h"


namespace sdklogs  = opentelemetry::sdk::logs;
namespace sdktrace  = opentelemetry::sdk::trace;
namespace logs_api = opentelemetry::logs;
namespace logs_exporter = opentelemetry::exporter::logs;

void initLogger()
{
  // Create the configuration options for the elasticsearch exporter, where:
  //     - host              = "localhost"
  //     - port              = 3000
  //     - index             = "content"
  //     - timeout           = 10 seconds
  //     - console debugging = true
  logs_exporter::ElasticsearchExporterOptions options("localhost", 9200, "content", 10, true);

  // Create an elasticsearch exporter with the options from above
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new logs_exporter::ElasticsearchLogExporter(options));

  // Attach the exporter to a processor
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));
  
  // Create a loggerprovider and attach the processor
  auto sdkProvider = std::shared_ptr<sdklogs::LoggerProvider>(new sdklogs::LoggerProvider());
  sdkProvider->SetProcessor(processor);
  auto apiProvider = nostd::shared_ptr<logs_api::LoggerProvider>(sdkProvider);

  // Set the global logger provider
  logs_api::Provider::SetLoggerProvider(apiProvider);
}

int main()
{
  // Setup the logging pipeline
  initLogger();
  
  // Get a logger instance
  auto logger = logs_api::Provider::GetLoggerProvider()->GetLogger("my logger");

  int log_choice;
  std::cout << "Enter log choice: ";
  std::cin >> log_choice;

  // Write a log statement based off the user's input
  switch(log_choice)
  {
    case 1:
      logger->Log(logs_api::Severity::kDebug, "Debug message");
      break;
    case 2:
      logger->Error("Error log with map", {{"Key1", "Value1"}, {"Key2", "Value2"}});
      break;
    case 3:
      // Set up tracer for context injection
      std::unique_ptr<opentelemetry::exporter::memory::InMemorySpanExporter> trace_exporter(
      new opentelemetry::exporter::memory::InMemorySpanExporter());
      auto trace_processor = std::make_shared<sdktrace::SimpleSpanProcessor>(std::move(trace_exporter));
      auto trace_provider  = opentelemetry::nostd::shared_ptr<opentelemetry::trace::TracerProvider>(
          new sdktrace::TracerProvider(trace_processor));
      opentelemetry::trace::Provider::SetTracerProvider(trace_provider);

      // Create a tracer and start a span for span context
      auto tracer      = trace_provider->GetTracer("foo_library");
      auto span_first  = tracer->StartSpan("span 1");
      auto scope_first = tracer->WithActiveSpan(span_first);
      auto span_second = tracer->StartSpan("span 2");

      logger->Warn("Log with trace context");
  }
}
