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
include sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/depend.make

# Include the progress variables for this target.
include sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/flags.make

sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.o: sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/flags.make
sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.o: sdk/test/metrics/histogram_aggregator_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics/histogram_aggregator_test.cc

sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics/histogram_aggregator_test.cc > CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.i

sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics/histogram_aggregator_test.cc -o CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.s

# Object files for target histogram_aggregator_test
histogram_aggregator_test_OBJECTS = \
"CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.o"

# External object files for target histogram_aggregator_test
histogram_aggregator_test_EXTERNAL_OBJECTS =

sdk/test/metrics/histogram_aggregator_test: sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/histogram_aggregator_test.cc.o
sdk/test/metrics/histogram_aggregator_test: sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/build.make
sdk/test/metrics/histogram_aggregator_test: sdk/src/metrics/libopentelemetry_metrics.a
sdk/test/metrics/histogram_aggregator_test: sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable histogram_aggregator_test"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/histogram_aggregator_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/build: sdk/test/metrics/histogram_aggregator_test

.PHONY : sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/build

sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics && $(CMAKE_COMMAND) -P CMakeFiles/histogram_aggregator_test.dir/cmake_clean.cmake
.PHONY : sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/clean

sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/test/metrics/CMakeFiles/histogram_aggregator_test.dir/depend

