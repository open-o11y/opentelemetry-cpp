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
include api/test/context/CMakeFiles/runtime_context_test.dir/depend.make

# Include the progress variables for this target.
include api/test/context/CMakeFiles/runtime_context_test.dir/progress.make

# Include the compile flags for this target's objects.
include api/test/context/CMakeFiles/runtime_context_test.dir/flags.make

api/test/context/CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.o: api/test/context/CMakeFiles/runtime_context_test.dir/flags.make
api/test/context/CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.o: api/test/context/runtime_context_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object api/test/context/CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context/runtime_context_test.cc

api/test/context/CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context/runtime_context_test.cc > CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.i

api/test/context/CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context/runtime_context_test.cc -o CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.s

# Object files for target runtime_context_test
runtime_context_test_OBJECTS = \
"CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.o"

# External object files for target runtime_context_test
runtime_context_test_EXTERNAL_OBJECTS =

api/test/context/runtime_context_test: api/test/context/CMakeFiles/runtime_context_test.dir/runtime_context_test.cc.o
api/test/context/runtime_context_test: api/test/context/CMakeFiles/runtime_context_test.dir/build.make
api/test/context/runtime_context_test: api/test/context/CMakeFiles/runtime_context_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runtime_context_test"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runtime_context_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
api/test/context/CMakeFiles/runtime_context_test.dir/build: api/test/context/runtime_context_test

.PHONY : api/test/context/CMakeFiles/runtime_context_test.dir/build

api/test/context/CMakeFiles/runtime_context_test.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context && $(CMAKE_COMMAND) -P CMakeFiles/runtime_context_test.dir/cmake_clean.cmake
.PHONY : api/test/context/CMakeFiles/runtime_context_test.dir/clean

api/test/context/CMakeFiles/runtime_context_test.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/api/test/context/CMakeFiles/runtime_context_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : api/test/context/CMakeFiles/runtime_context_test.dir/depend

