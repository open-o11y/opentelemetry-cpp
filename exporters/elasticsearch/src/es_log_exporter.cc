#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"
#include "opentelemetry/ext//http/client/curl//http_client_curl.h"
#include "opentelemetry/ext//http/client//http_client.h"
#include "opentelemetry/ext/http/server/http_server.h"

#include <assert.h>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <thread>
#include <vector>
#include <iostream>

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;



namespace curl        = opentelemetry::ext::http::client::curl;
namespace http_client = opentelemetry::ext::http::client;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{

class CustomEventHandler : public http_client::EventHandler
{
public:
  virtual void OnResponse(http_client::Response &response) noexcept override{};
  virtual void OnEvent(http_client::SessionState state,
                       opentelemetry::nostd::string_view reason) noexcept override
  {}
  virtual void OnConnecting(const http_client::SSLCertificate &) noexcept {}
  virtual ~CustomEventHandler() = default;
  bool is_called_               = false;
};

class PostEventHandler : public CustomEventHandler
{
  void OnResponse(http_client::Response &response) noexcept override
  {
    std::string body(response.GetBody().begin(), response.GetBody().end());
    is_called_ = true;
    std::cout << "Response received with body:" << std::endl;
    std::cout << body << std::endl;
  }
};

ElasticsearchLogExporter::ElasticsearchLogExporter() noexcept {}

sdklogs::ExportResult ElasticsearchLogExporter::Export(
    const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept
{
  if (isShutdown_)
  {
    return sdklogs::ExportResult::kFailure;
  }

  for (auto &r : records)
  {
    // Convert LogRecord to a JSON object
    json log;
    log["timestamp"] =  record->timestamp.time_since_epoch().count();
    log["severity"] =  record->severity;
    log["name"] =  record->name;
    log["body"] =  record->body;
    log["resource"] =  record->resource;
    log["attributes"] =  record->attributes;
    log["traceid"] =  record->traceid;
    log["spanid"] =  record->spanid;
    log["traceflags"] =  record->traceflags;
    logs.emplace_back(log);

    // for debugging
    cout << log.dump(4) << "\n";
  }

  // Send JSON object in HTTP request to elasticsearch here

  opentelemetry::ext::http::client::curl::SessionManager session_manager;

  int port;
  std::cout << "Enter port number: ";
  std::cin >> port;
  auto session = session_manager.CreateSession("127.0.0.1", port);
  auto request = session->CreateRequest();

  //Populate the request with headers and methods
  request->SetUri("logs/_doc?pretty");
  request->SetMethod(http_client::Method::Post);
  request->AddHeader("Content-Type", "application/json");

  //Add the request body
  std::string str_body = "{"
  "\"@timestamp\": \"2099-11-15T13:12:00\","
  "\"message\": \"GET /search HTTP/1.1 200 1070000\","
  "\"user\": {"
    "\"id\": \"max\""
  "}"
  "}";
  std::vector<uint8_t> body_vec(str_body.begin(), str_body.end());
  request->SetBody(body_vec);

  //Send the request
  PostEventHandler *handler = new PostEventHandler();
  std::cout << "Sending request" << std::endl;
  std::cout << "----------------" << std::endl;
  session->SendRequest(*handler);
  session->FinishSession();
  delete handler;

  return sdklogs::ExportResult::kSuccess;
}

void ElasticsearchLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept
{
  isShutdown_ = true;
}

}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
