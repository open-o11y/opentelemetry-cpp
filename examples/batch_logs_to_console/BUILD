cc_binary(
    name = "logs_batch_example",
    srcs = [
        "main.cc",
    ],
    linkopts = ["-lpthread"],
    deps = [
        "//api",
        "//exporters/ostream:ostream_log_exporter",
        "//sdk/src/logs",
    ],
)
