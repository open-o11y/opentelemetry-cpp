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

namespace curl        = opentelemetry::ext::http::client::curl;
namespace http_client = opentelemetry::ext::http::client;

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

int main()
{
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
}
