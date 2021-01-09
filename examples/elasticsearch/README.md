# ElasticSearch Exporter example

In this example, the application in `main.cc` initializes a connection to ElasticSearch using an Elasticsearch exporter instance, and uses it to register a logger provider from the [OpenTelemetry SDK](https://github.com/open-telemetry/opentelemetry-cpp). The application then calls a `foo_library` which has been instrumented using the [OpenTelemetry API](https://github.com/open-telemetry/opentelemetry-cpp/tree/master/api), and it writes several logging statements which are sent through the Elasticsearch exporter to an Elasticsearch instance.

To setup the Elasticsearch instance and build the example, follow the steps listed in the next two sections.

## Setting up Elasticsearch
1. Download Elasticsearch [from the elastic homepage](https://www.elastic.co/downloads/elasticsearch), and run  `bin/elasticsearch` (or `bin\elasticsearch.bat` on windows). An Elasticsearch instance will now be running on the default endpoint of `localhost:9200`.
2. *(Optional)* For data visualization, download Kibana [from the kibana homepage](https://www.elastic.co/downloads/elasticsearch), and run `bin/elasticsearch` (or `bin\elasticsearch.bat` on windows). After several seconds of setup, a Kibana instance will be running, and can be interacted with at the endpoint `localhost:5601`.

## Building the example
***Bazel***

With the ElasticSearch instance running, this example can now be built with Bazel and executed by running the following two commands:
1. Navigate to the root folder of the OpenTelemetry project. Run `bazel build examples/elasticsearch/...`
2. Run the generated executable, by typing `bazel-bin/examples/elasticsearch/logs_es_example`. By default, the application writes logs to the Elasticsearch index `logs`. This can be modified at runtime by passing an optional argument to the executable, for example `bazel-bin/examples/elasticsearch/logs_es_example my_custom_index`

***CMake***

Currently, the Elasticsearch exporter cannot be built using CMake due to a third party library restriction. This functionality is in development, and will be added at a future date.

## Viewing the data
After running the executable, Elasticsearch will now contain the log data that was written by `foo_library`. This data can be viewed by either interfacing with Elasticsearch directly, or by using Kibana.

***Viewing through Elasticsearch***

Type `curl -X GET 'http://localhost:9200/logs/_search?pretty=true'` into a terminal. This querys Elasticsearch for any data under the `logs` index that has a severity of `WARN`. The `pretty=true` portion is optional, but it makes the response from elasticsearch formatted in a human readable way.  The output will contain the 8 logs stored in that index.

***Viewing through Kibana***

1. Navigate to `localhost:5601` and click on the `Manage` button in the top right corner. Click on `Index Patterns` and then `Create Index Pattern`. Enter `logs` (or the custom name of your index) into the index pattern name and go to next step. Click create `Create index pattern`.
2. Navigate back to `localhost:5601` and click on the Kibana tile. Click `Discover`, and on the left bar, select the dropdown and choose the newly created index pattern to filter the data by. Kibana should now display the 8 logs stored in that index.
