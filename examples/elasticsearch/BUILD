cc_library(
    name = "foo_library",
    srcs = [
        "foo_library/foo_library.cc",
    ],
    hdrs = [
        "foo_library/foo_library.h",
    ],
    deps = [
        "//api",
    ],
)

cc_binary(
    name = "logs_es_example",
    srcs = [
        "main.cc",
    ],
    linkopts = ["-lpthread"],
    deps = [
        ":foo_library",
        "//api",
        "//exporters/memory:in_memory_span_exporter",
        "//exporters/elasticsearch:es_log_exporter",
        "//sdk/src/logs",
        "@curl",
    ],
)
