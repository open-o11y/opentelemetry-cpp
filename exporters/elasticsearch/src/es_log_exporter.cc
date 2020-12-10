#include "opentelemetry/exporters/elasticsearch/es_log_exporter.h"

#include <iostream>

#define CONSOLE_OUTPUT true

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;
namespace http_client = opentelemetry::ext::http::client;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{
// This class handle's the response message from the Elasticsearch request
class ResponseHandler : public http_client::EventHandler
{
public:
  void OnResponse(http_client::Response &response) noexcept override
  {
    // Store the body of the request
    body_ = std::string(response.GetBody().begin(), response.GetBody().end());

    // Set the response_received_ flag to true and notify any threads waiting on this result
    response_received_ = true;
    cv_.notify_all();
  }
  
  // A method the user calls to block their thread until the response is received, or the timeout is 
  // exceeded.
  bool waitForResponse(unsigned int timeoutSec = 1)
  {
    std::mutex mutex_;
    std::unique_lock<std::mutex> lk(mutex_);
    if (cv_.wait_for(lk, std::chrono::milliseconds(1000 * timeoutSec),
                               [&] { return response_received_; }))
    {
      return true;
    }
    return false;
  }

  std::string GetResponseBody()
  {
    if(!response_received_)
      return "No response";
    
    return body_;
  }

  // Virtual method definition
  void OnEvent(http_client::SessionState state,
                       opentelemetry::nostd::string_view reason) noexcept override
  {}
  

private:
  // Define a mutex and condition variable
  std::condition_variable cv_;

  // Whether the response from Elasticsearch has been received
  bool response_received_ = false;

  // A string to store the response body
  std::string body_ = "";
};

ElasticsearchLogExporter::ElasticsearchLogExporter() : 
  options_(ElasticsearchExporterOptions()) {}

ElasticsearchLogExporter::ElasticsearchLogExporter(const ElasticsearchExporterOptions &options) : 
  options_{options} {}

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
  }

  // Create a connection to the ElasticSearch instance
  opentelemetry::ext::http::client::curl::SessionManager session_manager;
  auto session = session_manager.CreateSession(options_.host_, options_.port_);
  auto request = session->CreateRequest();

  // Populate the request with headers and methods
  request->SetUri(options_.uri_ + "/_bulk?pretty");
  request->SetMethod(http_client::Method::Post);
  request->AddHeader("Content-Type", "application/json");

  // Add the request body
  std::string body = "";
  for(int i = 0; i < logs.size(); i++)
  {
    // Append the index:{} before JSON body, which tells Elasticsearch to use index passed from user
    body += "{\"index\" : {}}\n";

    // Add the context of the Log Record
    body += logs[i].dump() + "\n";
  }
  std::vector<uint8_t> body_vec(body.begin(), body.end());
  request->SetBody(body_vec);
  
  // Send the request
  ResponseHandler *handler = new ResponseHandler();
  session->SendRequest(*handler);
  
  // Wait for the response to be received
  if(CONSOLE_OUTPUT)
      std::cout << "waiting for response from Elasticsearch (timeout = " 
                << 4 << " seconds)" << std::endl;
  bool receivedResponse = handler->waitForResponse(4);

  // If the response was never received
  if(!receivedResponse)
  { 
    // TODO, retry logic

    if(CONSOLE_OUTPUT)
      std::cout << "No response was received" << std::endl;

    session->FinishSession();
    delete handler;

    return sdklogs::ExportResult::kSuccess;
  }

  if(CONSOLE_OUTPUT)
      std::cout << "Response received" << std::endl;

  // Parse the response output to determine if the request wasen't successful
  std::string responseBody = handler->GetResponseBody();
  if(responseBody.find("\"failed\" : 0") == std::string::npos)
  {
    if(CONSOLE_OUTPUT)
      std::cout << "Write to Elasticsearch failed" << std::endl;

    // TODO: Retry logic
    return sdklogs::ExportResult::kFailure;
  }

  //Clear the logs array, and clean up the HTTP client
  logs.clear();
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
