# Currently not working, waiting on issue #390 for bazel support
# https://github.com/open-telemetry/opentelemetry-cpp/issues/390

cc_binary(
    name = "http_example",
    srcs = [
        "main.cc",
    ],
    linkopts = select({
        "//bazel:windows": [],
        "//conditions:default": ["-pthread"],
    }),
    deps = [
        "//api",
        "//ext:headers",
        "//sdk/src/trace",
    ],
)
