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
include exporters/ostream/CMakeFiles/ostream_span_test.dir/depend.make

# Include the progress variables for this target.
include exporters/ostream/CMakeFiles/ostream_span_test.dir/progress.make

# Include the compile flags for this target's objects.
include exporters/ostream/CMakeFiles/ostream_span_test.dir/flags.make

exporters/ostream/CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.o: exporters/ostream/CMakeFiles/ostream_span_test.dir/flags.make
exporters/ostream/CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.o: exporters/ostream/test/ostream_span_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exporters/ostream/CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream/test/ostream_span_test.cc

exporters/ostream/CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream/test/ostream_span_test.cc > CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.i

exporters/ostream/CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream/test/ostream_span_test.cc -o CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.s

# Object files for target ostream_span_test
ostream_span_test_OBJECTS = \
"CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.o"

# External object files for target ostream_span_test
ostream_span_test_EXTERNAL_OBJECTS =

exporters/ostream/ostream_span_test: exporters/ostream/CMakeFiles/ostream_span_test.dir/test/ostream_span_test.cc.o
exporters/ostream/ostream_span_test: exporters/ostream/CMakeFiles/ostream_span_test.dir/build.make
exporters/ostream/ostream_span_test: exporters/ostream/libopentelemetry_exporter_ostream_span.a
exporters/ostream/ostream_span_test: exporters/ostream/CMakeFiles/ostream_span_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ostream_span_test"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ostream_span_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exporters/ostream/CMakeFiles/ostream_span_test.dir/build: exporters/ostream/ostream_span_test

.PHONY : exporters/ostream/CMakeFiles/ostream_span_test.dir/build

exporters/ostream/CMakeFiles/ostream_span_test.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream && $(CMAKE_COMMAND) -P CMakeFiles/ostream_span_test.dir/cmake_clean.cmake
.PHONY : exporters/ostream/CMakeFiles/ostream_span_test.dir/clean

exporters/ostream/CMakeFiles/ostream_span_test.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/exporters/ostream/CMakeFiles/ostream_span_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exporters/ostream/CMakeFiles/ostream_span_test.dir/depend

