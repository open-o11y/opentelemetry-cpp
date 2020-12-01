include_directories(include)

add_library(opentelemetry_exporter_ostream_logs src/log_exporter.cc) 

if(BUILD_TESTING)
  add_executable(ostream_log_test test/ostream_log_test.cc) 
  target_link_libraries(
    ostream_log_test ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}
    opentelemetry_exporter_ostream_logs) 

  gtest_add_tests(TARGET ostream_log_test TEST_PREFIX exporter. TEST_LIST
                  ostream_log_test) 
endif() # BUILD_TESTING
