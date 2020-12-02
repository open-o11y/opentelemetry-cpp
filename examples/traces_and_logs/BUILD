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
    name = "example_traces_and_logs",
    srcs = [
        "main.cc",
    ],
    deps = [
        ":foo_library",
        "//api",
        "//exporters/ostream:ostream_log_exporter",
        "//exporters/ostream:ostream_span_exporter",
        "//sdk/src/logs",
        "//sdk/src/trace",
    ],
)
