cc_binary(
    name = "logs_es_example",
    srcs = [
        "main.cc",
    ],
    linkopts = ["-lpthread"],
    deps = [
        "//api",
        "//exporters/memory:in_memory_span_exporter",
        "//exporters/elasticsearch:es_log_exporter",
        "//sdk/src/logs",
        "@curl",
    ],
)
