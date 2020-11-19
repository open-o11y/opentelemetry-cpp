# CMake generated Testfile for 
# Source directory: /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory
# Build directory: /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(exporter.InMemorySpanData.AddRecordable "/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory/in_memory_span_data_test" "--gtest_filter=InMemorySpanData.AddRecordable")
set_tests_properties(exporter.InMemorySpanData.AddRecordable PROPERTIES  _BACKTRACE_TRIPLES "/usr/local/Cellar/cmake/3.18.2/share/cmake/Modules/GoogleTest.cmake;378;add_test;/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory/CMakeLists.txt;20;gtest_add_tests;/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory/CMakeLists.txt;0;")
add_test(exporter.InMemorySpanExporter.ExportBatch "/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory/in_memory_span_exporter_test" "--gtest_filter=InMemorySpanExporter.ExportBatch")
set_tests_properties(exporter.InMemorySpanExporter.ExportBatch PROPERTIES  _BACKTRACE_TRIPLES "/usr/local/Cellar/cmake/3.18.2/share/cmake/Modules/GoogleTest.cmake;378;add_test;/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory/CMakeLists.txt;22;gtest_add_tests;/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/memory/CMakeLists.txt;0;")
