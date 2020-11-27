#include "opentelemetry/trace/provider.h"
#include "opentelemetry/logs/provider.h"

// Traces
namespace trace = opentelemetry::trace;
namespace nostd = opentelemetry::nostd;

// Logs
namespace logs  = opentelemetry::logs;
namespace nostd = opentelemetry::nostd;
using opentelemetry::logs::Severity;

namespace
{
nostd::shared_ptr<trace::Tracer> get_tracer()
{
  auto provider = trace::Provider::GetTracerProvider();
  return provider->GetTracer("foo_library");
}

nostd::shared_ptr<logs::Logger> get_logger()
{
  auto provider = logs::Provider::GetLoggerProvider();
  return provider->GetLogger("foo_library");
}

void f1()
{
  auto span  = get_tracer()->StartSpan("f1");
  auto scope = get_tracer()->WithActiveSpan(span);
  get_logger()->log("msg from f1");
  span->End();
}

void f2()
{
  auto span  = get_tracer()->StartSpan("f2");
  auto scope = get_tracer()->WithActiveSpan(span);
  get_logger()->log(Severity::kTrace, "msg from f2");

  f1();
  f1();

  span->End();
}
}  // namespace

void foo_library()
{
  auto span  = get_tracer()->StartSpan("library");
  auto scope = get_tracer()->WithActiveSpan(span);
  get_logger()->log(Severity::kInfo, "msg from foo_library");

  f2();

  span->End();
}
