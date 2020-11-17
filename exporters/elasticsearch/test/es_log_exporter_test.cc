#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"
#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/sdk/logs/exporter.h"

#include <gtest/gtest.h>
#include <iostream>

namespace sdklogs  = opentelemetry::sdk::logs;
namespace logs_api = opentelemetry::logs;
namespace nostd    = opentelemetry::nostd;

// TBD
TEST(ElasticsearchLogsExporter, PrintEmpty) {
    
}
TEST(ElasticsearchLogsExporter, PrintTimestamp) {}
TEST(ElasticsearchLogsExporter, PrintTraceFlags) {}
TEST(ElasticsearchLogsExporter, PrintBody) {}
TEST(ElasticsearchLogsExporter, PrintKeyValueIterable) {}
