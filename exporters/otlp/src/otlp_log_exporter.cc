#include "opentelemetry/exporters/otlp/otlp_log_exporter.h"

#include <grpcpp/grpcpp.h>
#include <iostream>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace otlp
{

// ----------------------------- Helper functions ------------------------------

/**
 * Add span protobufs contained in recordables to request.
 * @param records the records to export
 * @param request the current request
 */
void PopulateRequest(const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records,
                     proto::collector::logs::v1::ExportLogsServiceRequest *request)
{
  // auto resource_span       = request->add_resource_records();
  // auto instrumentation_lib = resource_span->add_instrumentation_library_records();

  // for (auto &LogRecord : records)
  // {
  //   auto rec = std::unique_ptr<opentelemetry::logs::LogRecord>(static_cast<LogRecord *>(LogRecord.release()));
  //   *instrumentation_lib->add_records() = std::move(rec->span());
  // }
}

/**
 * Create service stub to communicate with the OpenTelemetry Collector.
 */
std::unique_ptr<proto::collector::logs::v1::LogsService::Stub> MakeServiceStub(
    std::string endpoint)
{
  auto channel = grpc::CreateChannel(endpoint, grpc::InsecureChannelCredentials());
  return proto::collector::logs::v1::LogsService::NewStub(channel);
}

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

sdk::logs::ExportResult OtlpLogExporter::Export(
    const std::vector<std::unique_ptr<opentelemetry::logs::LogRecord>> &records) noexcept
{
  proto::collector::logs::v1::ExportLogsServiceRequest request;

  PopulateRequest(records, &request);

  grpc::ClientContext context;
  proto::collector::logs::v1::ExportLogsServiceResponse response;

  grpc::Status status = log_service_stub_->Export(&context, request, &response);

  if (!status.ok())
  {
    std::cerr << "[OTLP Exporter] Export() failed: " << status.error_message() << "\n";
    return sdk::logs::ExportResult::kFailure;
  }
  return sdk::logs::ExportResult::kSuccess;
}

void OtlpLogExporter::Shutdown(std::chrono::microseconds timeout) noexcept{}

}  // namespace otlp
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
