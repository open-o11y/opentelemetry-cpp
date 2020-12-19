
# Batch Logs Example

In this example, the application in `main.cc` initializes and registers a logger
provider from the [OpenTelemetry SDK](https://github.com/open-telemetry/opentelemetry-cpp).
The application then calls a `foo_library` which has been instrumented using
the [OpenTelemetry API](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/api).
Resulting telemetry is directed to stdout through the OStreamLogExporter.

Commands to run:

``sh
bazel build //examples/logs_batch_ostream:logs_batch_example
bazel-bin/examples/logs_batch_ostream/logs_batch_example
``
