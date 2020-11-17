
# Simple Logs Example

In this example, the application in `main.cc` initializes and registers a logger
provider from the [OpenTelemetry SDK](https://github.com/open-telemetry/opentelemetry-cpp).
The application then calls a `foo_library` which has been instrumented using
the [OpenTelemetry API](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/api).
Resulting telemetry is directed to stdout through the OStreamLogExporter.

See [CONTRIBUTING.md](../../CONTRIBUTING.md) for instructions on building and running the example.

Commands to run:

``sh
bazel build //examples/logs_simple_ostream:logs_example_simple
bazel-bin/examples/logs_simple_ostream/logs_example_simple
``
