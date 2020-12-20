
# Simple Logs 

This example shows how logs are written using the [OpenTelemetry Logging API](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/api/include/opentelemetry/logs), then sent to an OStream throuogh the [OpenTelemetry Logging SDK](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/sdk/include/opentelemetry/sdk/logs)).

The steps to initializing a `Logger` to write logging statements with are as follows: 
1. Initialize a LoggerProvider. We will use this to obtain Loggers in the future.
2. Initialize an exporter. In this example, we will use the Ostream Log Exporter, configured to print to `stdout`.
3. Initialize an log processor. Here we'll use a simple processor.
4. Push the Logger Provider to the API
5. Set the global logger provider.

Example logging statements uses are shown in `foo_library`. 
 
See [CONTRIBUTING.md](../../CONTRIBUTING.md) for instructions on building and running the example.

```
bazel build //examples/logs_simple:logs_simple_example
bazel-bin/examples/logs_simple/logs_simple_example
```
