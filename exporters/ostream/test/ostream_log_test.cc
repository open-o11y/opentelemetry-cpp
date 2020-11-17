#include "opentelemetry/exporters/ostream/log_exporter.h"
#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/sdk/logs/exporter.h"

#include <gtest/gtest.h>
#include <iostream>

namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;
namespace nostd    = opentelemetry::nostd;

// TBD
TEST(OStreamLogsExporter, PrintEmpty) {}
TEST(OStreamLogsExporter, PrintTimestamp) {}
TEST(OStreamLogsExporter, PrintTraceFlags) {}
TEST(OStreamLogsExporter, PrintBody) {}
TEST(OStreamLogsExporter, PrintKeyValueIterable) {}
