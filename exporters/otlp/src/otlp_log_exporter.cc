#include "opentelemetry/exporters/otlp/otlp_log_exporter.h"

#include <grpcpp/grpcpp.h>
#include <iostream>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace otlp
{

// -------------------------------- Contructors --------------------------------

OtlpLogExporter::OtlpLogExporter() : OtlpLogExporter(OtlpLogExporterOptions()) {}

OtlpLogExporter::OtlpLogExporter(const OtlpLogExporterOptions &options)
    : options_(options), log_service_stub_(MakeServiceStub(options.endpoint))
{}

OtlpLogExporter::OtlpLogExporter(
    std::unique_ptr<proto::collector::logs::v1::LogsService::StubInterface> stub)
    : options_(OtlpLogExporterOptions()), log_service_stub_(std::move(stub))
{}

// ----------------------------- Exporter methods ------------------------------

/** 
 * Logs are currently not retried if export failed.
 */ 
sdk::logs::ExportResult OtlpLogExporter::Export(
    const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept
{
  if(isShutDown){
    return sdk::logs::ExportResult::Failure;
  }
  /**
   * Populate context, request, and response to pass to the Export() gRPC service request 
   * defined in https://github.com/open-telemetry/opentelemetry-proto/blob/master/opentelemetry/proto/collector/trace/v1/trace_service.proto#L29 
   */
  
  // Variables to store Context, Request, and Response 
  grpc::ClientContext context;
  proto::collector::logs::v1::ExportLogsServiceRequest request;
  proto::collector::logs::v1::ExportLogsServiceResponse response;


  /* Populate Request */

  // Set ResourceLogs for the request, as defined in https://github.com/open-telemetry/opentelemetry-proto/blob/master/opentelemetry/proto/collector/logs/v1/logs_service.proto#L44
  auto resource_logs       = request.add_resource_logs();

  // Set instrumentation library logs for ResourceLogs, as defined in  https://github.com/open-telemetry/opentelemetry-proto/blob/master/opentelemetry/proto/logs/v1/logs.proto#L34
  auto instrumentation_lib = resource_logs.add_instrumentation_library_logs();

  // Populate instrumentation library logs with list of LogRecords received by this exporter
  // as per https://github.com/open-telemetry/opentelemetry-proto/blob/master/opentelemetry/proto/logs/v1/logs.proto#L45
  for (auto & record : records)
  { 
    *instrumentation_lib->add_records() = record;
  }

  /**
   * Get status from  Export() call with context reference, request, and response reference passed in, 
   * and get status code to determine export failure or success. 
   */
  
  // gRPC status defined in: 
  grpc::Status status = log_service_stub_->Export(&context, request, &response);

  // 
  if (!status.ok())
  {
    std::cerr << "[OTLP Log Exporter] Export() failed: " << status.error_message() << "\n";
    return sdk::logs::ExportResult::kFailure;
  }
  return sdk::logs::ExportResult::kSuccess;
}

/**
 * Timeout functionality is currently not implemented
 */
bool OtlpLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept {
  isShutDown = true;

  // Clean up?


  return true;
}

}  // namespace otlp
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
