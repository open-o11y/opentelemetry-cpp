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
include examples/metrics_simple/CMakeFiles/simple_metrics.dir/depend.make

# Include the progress variables for this target.
include examples/metrics_simple/CMakeFiles/simple_metrics.dir/progress.make

# Include the compile flags for this target's objects.
include examples/metrics_simple/CMakeFiles/simple_metrics.dir/flags.make

examples/metrics_simple/CMakeFiles/simple_metrics.dir/main.cc.o: examples/metrics_simple/CMakeFiles/simple_metrics.dir/flags.make
examples/metrics_simple/CMakeFiles/simple_metrics.dir/main.cc.o: examples/metrics_simple/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/metrics_simple/CMakeFiles/simple_metrics.dir/main.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_metrics.dir/main.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple/main.cc

examples/metrics_simple/CMakeFiles/simple_metrics.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_metrics.dir/main.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple/main.cc > CMakeFiles/simple_metrics.dir/main.cc.i

examples/metrics_simple/CMakeFiles/simple_metrics.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_metrics.dir/main.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple/main.cc -o CMakeFiles/simple_metrics.dir/main.cc.s

# Object files for target simple_metrics
simple_metrics_OBJECTS = \
"CMakeFiles/simple_metrics.dir/main.cc.o"

# External object files for target simple_metrics
simple_metrics_EXTERNAL_OBJECTS =

examples/metrics_simple/simple_metrics: examples/metrics_simple/CMakeFiles/simple_metrics.dir/main.cc.o
examples/metrics_simple/simple_metrics: examples/metrics_simple/CMakeFiles/simple_metrics.dir/build.make
examples/metrics_simple/simple_metrics: examples/metrics_simple/CMakeFiles/simple_metrics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simple_metrics"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_metrics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/metrics_simple/CMakeFiles/simple_metrics.dir/build: examples/metrics_simple/simple_metrics

.PHONY : examples/metrics_simple/CMakeFiles/simple_metrics.dir/build

examples/metrics_simple/CMakeFiles/simple_metrics.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple && $(CMAKE_COMMAND) -P CMakeFiles/simple_metrics.dir/cmake_clean.cmake
.PHONY : examples/metrics_simple/CMakeFiles/simple_metrics.dir/clean

examples/metrics_simple/CMakeFiles/simple_metrics.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/metrics_simple/CMakeFiles/simple_metrics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/metrics_simple/CMakeFiles/simple_metrics.dir/depend

