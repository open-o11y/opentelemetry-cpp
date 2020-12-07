#include "opentelemetry/exporters/ostream/log_exporter.h"
#include "opentelemetry/logs/provider.h"
#include "opentelemetry/sdk/logs/logger_provider.h"
#include "opentelemetry/sdk/logs/simple_log_processor.h"

#include <gtest/gtest.h>
#include <iostream>

#include <gtest/gtest.h>
#include <iostream>

namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;
namespace nostd    = opentelemetry::nostd;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{

// Test that processor/exporter is shutdown, no logs should be sent to stream
TEST(OStreamLogExporter, Shutdown)
{
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new opentelemetry::exporter::logs::OStreamLogExporter);
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));

  auto record  = std::shared_ptr<logs_api::LogRecord>(new logs_api::LogRecord());
  record->name = "Test Log";

  // Create stringstream to redirect to
  std::stringstream stdoutOutput;

  // Save cout's buffer here
  std::streambuf *sbuf = std::cout.rdbuf();

  // Redirect cout to our stringstream buffer
  std::cout.rdbuf(stdoutOutput.rdbuf());

  processor->Shutdown();

  // After processor/exporter is shutdown, no logs should be sent to stream
  processor->OnReceive(record);

  std::cout.rdbuf(sbuf);

  ASSERT_EQ(stdoutOutput.str(), "");
}

// ---------------------------------- Print to cout, cerr, and clog -------------------------

// Print Log to std::cout
TEST(OStreamLogExporter, PrintLogToCout)
{
  // Initialize an Ostream exporter to cout
  auto exporter = std::unique_ptr<sdklogs::LogExporter>(
      new opentelemetry::exporter::logs::OStreamLogExporter(std::cout));
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));

  // Save original stream buffer and redirect cout to our new stream buffer
  std::streambuf *sbuf = std::cout.rdbuf();
  std::stringstream stdcoutOutput;
  std::cout.rdbuf(stdcoutOutput.rdbuf());

  // Create a log record and manually set all fields (since we are not using SDK to inject fields)
  opentelemetry::core::SystemTimestamp now(std::chrono::system_clock::now());
  opentelemetry::trace::SpanId span_id;
  opentelemetry::trace::TraceId trace_id;
  opentelemetry::trace::TraceFlags trace_flags;

  auto record         = std::shared_ptr<logs_api::LogRecord>(new logs_api::LogRecord());
  record->timestamp   = now;
  record->severity    = logs_api::Severity::kInfo;
  record->name        = "Test Log";
  record->body        = "Message";
  record->trace_id    = trace_id;
  record->span_id     = span_id;
  record->trace_flags = trace_flags;

  // Log a record to cout
  processor->OnReceive(record);

  // Reset cout's original stringstream buffer
  std::cout.rdbuf(sbuf);

  std::string expectedOutput =
      "{\n"
      "    timestamp   : " +
      std::to_string(now.time_since_epoch().count()) +
      "\n"
      "    severity    : 9\n"
      "    name        : Test Log\n"
      "    body        : Message\n"
      "    resource    : {}\n"
      "    attributes  : {}\n"
      "    trace_id    : 00000000000000000000000000000000\n"
      "    span_id     : 0000000000000000\n"
      "    trace_flags : 00\n"
      "}\n";
  ASSERT_EQ(stdcoutOutput.str(), expectedOutput);
}

// Print log to std::cerr
TEST(OStreamLogExporter, PrintLogToCerr)
{
  // Initialize an Ostream exporter to cerr
  auto exporter = std::unique_ptr<sdklogs::LogExporter>(
      new opentelemetry::exporter::logs::OStreamLogExporter(std::cerr));
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));

  // Save original stream buffer and redirect cerr to our new stream buffer
  std::streambuf *sbuf = std::cerr.rdbuf();
  std::stringstream stdcerrOutput;
  std::cerr.rdbuf(stdcerrOutput.rdbuf());

  // Create a log record and manually set all fields (since we are not using SDK to inject fields)
  opentelemetry::core::SystemTimestamp now(std::chrono::system_clock::now());
  opentelemetry::trace::SpanId span_id;
  opentelemetry::trace::TraceId trace_id;
  opentelemetry::trace::TraceFlags trace_flags;

  auto record         = std::shared_ptr<logs_api::LogRecord>(new logs_api::LogRecord());
  record->timestamp   = now;
  record->severity    = logs_api::Severity::kInfo;
  record->name        = "Test Log";
  record->body        = "Message";
  record->trace_id    = trace_id;
  record->span_id     = span_id;
  record->trace_flags = trace_flags;

  // Log a record to cerr
  processor->OnReceive(record);

  // Reset cerr's original stringstream buffer
  std::cerr.rdbuf(sbuf);

  std::string expectedOutput =
      "{\n"
      "    timestamp   : " +
      std::to_string(now.time_since_epoch().count()) +
      "\n"
      "    severity    : 9\n"
      "    name        : Test Log\n"
      "    body        : Message\n"
      "    resource    : {}\n"
      "    attributes  : {}\n"
      "    trace_id    : 00000000000000000000000000000000\n"
      "    span_id     : 0000000000000000\n"
      "    trace_flags : 00\n"
      "}\n";
  ASSERT_EQ(stdcerrOutput.str(), expectedOutput);
}

// Pirnt log to std::clog
TEST(OStreamLogExporter, PrintLogToClog)
{
  // Initialize an ostream exporter to clog
  auto exporter = std::unique_ptr<sdklogs::LogExporter>(
      new opentelemetry::exporter::logs::OStreamLogExporter(std::clog));
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));

  // Save original stream buffer and redirect clog to our new stream buffer
  std::streambuf *sbuf = std::clog.rdbuf();
  std::stringstream stdcerrOutput;
  std::clog.rdbuf(stdcerrOutput.rdbuf());

  // Create a log record and manually set all fields (since we are not using SDK to inject fields)
  opentelemetry::core::SystemTimestamp now(std::chrono::system_clock::now());
  opentelemetry::trace::SpanId span_id;
  opentelemetry::trace::TraceId trace_id;
  opentelemetry::trace::TraceFlags trace_flags;

  auto record         = std::shared_ptr<logs_api::LogRecord>(new logs_api::LogRecord());
  record->timestamp   = now;
  record->severity    = logs_api::Severity::kInfo;  // kInfo = 9
  record->name        = "Test Log";
  record->body        = "Message";
  record->trace_id    = trace_id;
  record->span_id     = span_id;
  record->trace_flags = trace_flags;

  using M = std::map<std::string, std::string>;
  M m     = {{"key1", "val1"}, {"key2", "val2"}};
  record->attributes =
      nostd::shared_ptr<common::KeyValueIterable>(new common::KeyValueIterableView<M>{m});

  // Log a record to clog
  processor->OnReceive(record);

  // Reset clog's original stringstream buffer
  std::clog.rdbuf(sbuf);

  std::string expectedOutput =
      "{\n"
      "    timestamp   : " +
      std::to_string(now.time_since_epoch().count()) +
      "\n"
      "    severity    : 9\n"
      "    name        : Test Log\n"
      "    body        : Message\n"
      "    resource    : {}\n"
      "    attributes  : {{key1: }, {key2: }}\n"
      "    trace_id    : 00000000000000000000000000000000\n"
      "    span_id     : 0000000000000000\n"
      "    trace_flags : 00\n"
      "}\n";
  ASSERT_EQ(stdcerrOutput.str(), expectedOutput);
}

// ---------------------------------- Integration Tests -------------------------

// Print a log using the full logging pipeline
TEST(OStreamLogExporter, IntegrationTest)
{
  // Initialize a logger
  auto exporter =
      std::unique_ptr<sdklogs::LogExporter>(new opentelemetry::exporter::logs::OStreamLogExporter);
  auto processor =
      std::shared_ptr<sdklogs::LogProcessor>(new sdklogs::SimpleLogProcessor(std::move(exporter)));
  auto sdkProvider = std::shared_ptr<sdklogs::LoggerProvider>(new sdklogs::LoggerProvider());
  sdkProvider->SetProcessor(processor);
  auto apiProvider = nostd::shared_ptr<logs_api::LoggerProvider>(sdkProvider);
  auto provider    = nostd::shared_ptr<logs_api::LoggerProvider>(apiProvider);
  logs_api::Provider::SetLoggerProvider(provider);
  auto logger = logs_api::Provider::GetLoggerProvider()->GetLogger("Logger");

  // Back up cout's streambuf
  std::streambuf *sbuf = std::cout.rdbuf();

  // Redirect cout to our string stream
  std::stringstream stdcoutOutput;
  std::cout.rdbuf(stdcoutOutput.rdbuf());

  // Write a log to ostream exporter
  // auto record = std::shared_ptr<logs_api::LogRecord>(new logs_api::LogRecord());
  logs_api::LogRecord record;
  opentelemetry::core::SystemTimestamp now(std::chrono::system_clock::now());
  record.timestamp = now;
  record.severity  = logs_api::Severity::kInfo;
  record.name      = "Name";
  record.body      = "Message";
  using M          = std::map<std::string, std::string>;
  M m              = {{"key1", "val1"}, {"key2", "val2"}};
  //   record.attributes  = nostd::shared_ptr<common::KeyValueIterable>(new
  //   common::KeyValueIterableView<M>{m}); record.attributes  = nullptr;

  logger->log(record);

  // Restore cout's original streambuf
  std::cout.rdbuf(sbuf);

  // Compare actual vs expected outputs
  std::string expectedOutput =
      "{\n"
      "    timestamp   : " +
      std::to_string(now.time_since_epoch().count()) +
      "\n"
      "    severity    : 9\n"
      "    name        : Name\n"
      "    body        : Message\n"
      "    resource    : {}\n"
      "    attributes  : {}\n"
      //   "    attributes  : {{key1: }, {key2: }}\n"
      "    trace_id    : 00000000000000000000000000000000\n"
      "    span_id     : 0000000000000000\n"
      "    trace_flags : 00\n"
      "}\n";

  ASSERT_EQ(stdcoutOutput.str(), expectedOutput);
}

}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
