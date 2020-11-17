#include "opentelemetry/logs/provider.h"

namespace logs  = opentelemetry::logs;
namespace nostd = opentelemetry::nostd;
using opentelemetry::logs::Severity;
namespace
{
nostd::shared_ptr<logs::Logger> get_logger()
{
  auto provider = logs::Provider::GetLoggerProvider();
  return provider->GetLogger("foo_library");
}

void f1()
{
  get_logger()->log("msg from f1");
}

void f2()
{
  get_logger()->log(Severity::kTrace, "msg from f2");

  f1();
  f1();
}
}  // namespace

void foo_library()
{
  get_logger()->log(Severity::kInfo, "msg from foo_library");

  f2();
}
