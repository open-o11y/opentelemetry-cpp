#pragma once

#include "opentelemetry/proto/collector/logs/v1/logs_service.grpc.pb.h"
#include "opentelemetry/sdk/logs/exporter.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace otlp
{
/**
 * Struct to hold OTLP exporter options.
 */
struct OtlpLogExporterOptions
{
  // The endpoint to export to. By default the OpenTelemetry Collector's default endpoint.
  std::string endpoint = "localhost:55680";
};

/**
 * The OTLP exporter exports span data in OpenTelemetry Protocol (OTLP) format.
 */
class OtlpLogExporter final : public opentelemetry::sdk::logs::LogExporter
{
public:
  /**
   * Create an OtlpLogExporter using all default options.
   */
  OtlpLogExporter();

  /**
   * Create an OtlpLogExporter using the given options.
   */
  OtlpLogExporter(const OtlpLogExporterOptions &options);

  /**
   * Export a batch of log records in OTLP format.
   * @param records a span of shared pointers to log records
   */
  sdk::logs::ExportResult Export(const std::span<std::shared_ptr<opentelemetry::logs::LogRecord>>
                                     &records) noexcept override;

  /**
   * Shut down the exporter. 
   * @param timeout an optional timeout to abort the function within. 
   * Note the timeout functionality is currently not implemented yet.
   */
  void Shutdown(std::chrono::microseconds timeout = std::chrono::microseconds::max()) noexcept override;

private:
  // The configuration options associated with this exporter.
  const OtlpLogExporterOptions options_;

  // For testing
  friend class OtlpLogExporterTestPeer;

  // Store service stub internally. Useful for testing.
  std::unique_ptr<proto::collector::logs::v1::LogsService::StubInterface> log_service_stub_;

  /**
   * Create an OtlpLogExporter using the specified service stub.
   * Only tests can call this constructor directly.
   * @param stub the service stub to be used for exporting
   */
  OtlpLogExporter(std::unique_ptr<proto::collector::logs::v1::LogsService::StubInterface> stub);


  /**x
   * Create service stub to communicate with the OpenTelemetry Collector.
   */
  std::unique_ptr<proto::collector::logs::v1::LogsService::Stub> MakeServiceStub(std::string endpoint)
  {
    auto channel = grpc::CreateChannel(endpoint, grpc::InsecureChannelCredentials());
    return proto::collector::logs::v1::LogsService::NewStub(channel);
  }

  // Whether this exporter has been shut down
  bool isShutDown = false; 
;
}  // namespace otlp
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
