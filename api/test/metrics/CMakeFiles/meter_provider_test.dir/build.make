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
include api/test/metrics/CMakeFiles/meter_provider_test.dir/depend.make

# Include the progress variables for this target.
include api/test/metrics/CMakeFiles/meter_provider_test.dir/progress.make

# Include the compile flags for this target's objects.
include api/test/metrics/CMakeFiles/meter_provider_test.dir/flags.make

api/test/metrics/CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.o: api/test/metrics/CMakeFiles/meter_provider_test.dir/flags.make
api/test/metrics/CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.o: api/test/metrics/meter_provider_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object api/test/metrics/CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics/meter_provider_test.cc

api/test/metrics/CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics/meter_provider_test.cc > CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.i

api/test/metrics/CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics/meter_provider_test.cc -o CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.s

# Object files for target meter_provider_test
meter_provider_test_OBJECTS = \
"CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.o"

# External object files for target meter_provider_test
meter_provider_test_EXTERNAL_OBJECTS =

api/test/metrics/meter_provider_test: api/test/metrics/CMakeFiles/meter_provider_test.dir/meter_provider_test.cc.o
api/test/metrics/meter_provider_test: api/test/metrics/CMakeFiles/meter_provider_test.dir/build.make
api/test/metrics/meter_provider_test: api/test/metrics/CMakeFiles/meter_provider_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable meter_provider_test"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/meter_provider_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
api/test/metrics/CMakeFiles/meter_provider_test.dir/build: api/test/metrics/meter_provider_test

.PHONY : api/test/metrics/CMakeFiles/meter_provider_test.dir/build

api/test/metrics/CMakeFiles/meter_provider_test.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics && $(CMAKE_COMMAND) -P CMakeFiles/meter_provider_test.dir/cmake_clean.cmake
.PHONY : api/test/metrics/CMakeFiles/meter_provider_test.dir/clean

api/test/metrics/CMakeFiles/meter_provider_test.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/metrics/CMakeFiles/meter_provider_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : api/test/metrics/CMakeFiles/meter_provider_test.dir/depend

