include_directories(${CMAKE_SOURCE_DIR}/ext/include)

find_package(CURL)
if(CURL_FOUND)
  set(CURL_LIBRARY "-lcurl")
  add_executable(example_http main.cc)
  include_directories(${CURL_INCLUDE_DIR})
  target_link_libraries(example_http ${CMAKE_THREAD_LIBS_INIT} 
  ${CURL_LIBRARIES})
endif()
