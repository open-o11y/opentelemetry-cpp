
# Simple Traces and Correlated Logs Example

In this example, the application in `main.cc` initializes and registers a tracer
provider and logger provider from the [OpenTelemetry SDK](https://github.com/open-telemetry/opentelemetry-cpp).
The application then calls a `foo_library` which has been instrumented using
the [OpenTelemetry API](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/api).
Resulting telemetry is directed to stdout through the  OStream Span Exporter. and OStream Log Exporter.

**Commands to build and run the example:**
```
bazel build //examples/traces_and_logs:example_traces_and_logs
bazel-bin/examples/traces_and_logs/example_traces_and_logs
```
