#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"

#include <iostream>

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;
namespace http_client = opentelemetry::ext::http::client;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{

// This class handle's the response message from the Elasticsearch request
class PostEventHandler : public http_client::EventHandler
{
public:
  void OnResponse(http_client::Response &response) noexcept override
  {
    std::string body(response.GetBody().begin(), response.GetBody().end());

    // TODO: Parse the body to determine if the request was successful
  }
  virtual void OnEvent(http_client::SessionState state,
                       opentelemetry::nostd::string_view reason) noexcept override
  {}
  virtual void OnConnecting(const http_client::SSLCertificate &) noexcept {}
  virtual ~PostEventHandler() = default;
};

ElasticsearchLogExporter::ElasticsearchLogExporter() noexcept : 
  host_{"localhost"}, port_{9200}, uri_{""} {}

ElasticsearchLogExporter::ElasticsearchLogExporter(std::string_view host, int port) noexcept : 
  host_{host}, port_{port}, uri_{""} {}

sdklogs::ExportResult ElasticsearchLogExporter::Export(
    const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept
{
  if (isShutdown_)
  {
    return sdklogs::ExportResult::kFailure;
  }

  for (auto &record : records)
  {
    // Convert LogRecord to a JSON object 
    json log; 
    log["timestamp"] =  record->timestamp.time_since_epoch().count();
    log["severity"] =  record->severity; 
    log["name"] =  record->name;
    log["body"] =  record->body;

    char trace_buf[32];
    record->trace_id.ToLowerBase16(trace_buf);
    log["traceid"] =  std::string(trace_buf, sizeof(trace_buf));

    char span_buf[16];
    record->span_id.ToLowerBase16(span_buf);
    log["spanid"] =  std::string(span_buf, sizeof(span_buf));

    char flag_buf[2];
    record->trace_flag.ToLowerBase16(flag_buf);
    log["traceflags"] =  std::string(flag_buf, sizeof(flag_buf));

    // TODO: Write resource and attributes into JSON 
    // log["resource"] =  record->resource;
    // log["attributes"] =  record->attributes;
    logs.emplace_back(log);

    // Create a connection to the ElasticSearch instance
    opentelemetry::ext::http::client::curl::SessionManager session_manager;
    auto session = session_manager.CreateSession(host_.data(), port_);
    auto request = session->CreateRequest();

    // Populate the request with headers and methods
    std::string uri_full = uri_.data();
    uri_full += "/_doc?pretty";
    request->SetUri(uri_full);
    request->SetMethod(http_client::Method::Post);
    request->AddHeader("Content-Type", "application/json");

    // Add the request body
    std::string body = log.dump(4);
    std::vector<uint8_t> body_vec(body.begin(), body.end());
    request->SetBody(body_vec);
    
    // Send the request
    PostEventHandler *handler = new PostEventHandler();
    session->SendRequest(*handler);
    session->FinishSession();
    delete handler;
  }
  return sdklogs::ExportResult::kSuccess;
}

void ElasticsearchLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept
{
  isShutdown_ = true;
}

void ElasticsearchLogExporter::SetURI(std::string_view uri) noexcept
{
  uri_ = uri;
}

}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
