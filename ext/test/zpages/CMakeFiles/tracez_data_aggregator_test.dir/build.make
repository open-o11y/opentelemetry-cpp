# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter

# Include any dependencies generated for this target.
include ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/depend.make

# Include the progress variables for this target.
include ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/progress.make

# Include the compile flags for this target's objects.
include ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/flags.make

ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.o: ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/flags.make
ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.o: ext/test/zpages/tracez_data_aggregator_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages/tracez_data_aggregator_test.cc

ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages/tracez_data_aggregator_test.cc > CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.i

ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages/tracez_data_aggregator_test.cc -o CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.s

# Object files for target tracez_data_aggregator_test
tracez_data_aggregator_test_OBJECTS = \
"CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.o"

# External object files for target tracez_data_aggregator_test
tracez_data_aggregator_test_EXTERNAL_OBJECTS =

ext/test/zpages/tracez_data_aggregator_test: ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/tracez_data_aggregator_test.cc.o
ext/test/zpages/tracez_data_aggregator_test: ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/build.make
ext/test/zpages/tracez_data_aggregator_test: ext/src/zpages/libopentelemetry_zpages.a
ext/test/zpages/tracez_data_aggregator_test: sdk/src/trace/libopentelemetry_trace.a
ext/test/zpages/tracez_data_aggregator_test: sdk/src/common/libopentelemetry_common.a
ext/test/zpages/tracez_data_aggregator_test: ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tracez_data_aggregator_test"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tracez_data_aggregator_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/build: ext/test/zpages/tracez_data_aggregator_test

.PHONY : ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/build

ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages && $(CMAKE_COMMAND) -P CMakeFiles/tracez_data_aggregator_test.dir/cmake_clean.cmake
.PHONY : ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/clean

ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/test/zpages/CMakeFiles/tracez_data_aggregator_test.dir/depend

