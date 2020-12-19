
# Simple Logging and Tracing Example

In this example, the application in `main.cc` initializes and registers a tracer
provider and logger provider from the [OpenTelemetry SDK](https://github.com/open-telemetry/opentelemetry-cpp).
The application then calls a `foo_library` which has been instrumented using
the [OpenTelemetry API](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/api).
Resulting telemetry is directed to stdout through the  OStream Span Exporter. and OStream Log Exporter.

## Usage

The steps to initializing a Logger and writing the first logging statement is described below.

1. Initialize a LoggerProvider. We will use this to obtain Loggers in the future.

```
auto logger_provider = std::shared_ptr<sdk::logs::LoggerProvider>(new sdklogs::LoggerProvider());
```

2. Initialize an exporter. In this example, we will use the Ostream Log Exporter, configured to print to `stdout`.

```
auto exporter = std::unique_ptr<sdk::logs::LogExporter>(new opentelemetry::exporter::logs::OStreamLogExporter);
```

3. Initialize an log processor. Here we'll use a simple processor.

```
auto processor = std::shared_ptr<sdk::logs::LogProcessor>(new sdk::logs::SimpleLogProcessor(std::move(exporter)));
```

4. Convert the SDK Logger Provider instance created to an API Logger Provider.

```
auto api_logger_provider = nostd::shared_ptr<logs_api::LoggerProvider>(logger_provider);
```

5. Set the logger provider created as the global one.

```
auto provider = nostd::shared_ptr<logs_api::LoggerProvider>(api_logger_provider);
Provider::SetLoggerProvider(provider);
```

6. Get a Logger

```
auto logger = provider->GetLogger("logger_name");
```

7. Write a Log

```
logger->Log("Hello, World!");
```


A runnable example can be found in [/examples/logs_simple](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/examples/logs_simple) folder.


See [CONTRIBUTING.md](../../CONTRIBUTING.md) for instructions on building and running the example.