# ElasticSearch HTTP example

In this example, the application in `main.cc` initializes a connection to an ElasticSearch instance and writes several log records to it using a simple processor. Before we can run the test, we need to set up an elastic search instance locally. Follow the steps below to do this:

## Setting up ElasticSearch
1. Download elasticsearch from the main homepage then unzip it.
2. In a terminal, navigate inside the unzipped folder. Once there, start the elasticsearch instance by typing `./bin/elasticsearch`.
3. Wait for the outputs to the console to stop, then locate the line where it says what port ElasticSearch is running on. By default it is port 9200.

## Running the example
With the ElasticSearch instance running, this example can now be built and ran by running the following two commands:

1. Navigate to the root folder of OpenTelemetry. Run `bazel build examples/elasticsearch_logs/...`
2. Bazel has now built the example into an executable, which is executed by running `bazel-bin/examples/elasticsearch_logs/logs_es_example`
