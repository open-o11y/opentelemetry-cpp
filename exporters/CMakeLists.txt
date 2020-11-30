
add_subdirectory(ostream)
add_subdirectory(memory)

if(WITH_PROMETHEUS)
  add_subdirectory(prometheus)
endif()
