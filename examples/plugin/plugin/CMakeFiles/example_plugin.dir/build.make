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
include examples/plugin/plugin/CMakeFiles/example_plugin.dir/depend.make

# Include the progress variables for this target.
include examples/plugin/plugin/CMakeFiles/example_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include examples/plugin/plugin/CMakeFiles/example_plugin.dir/flags.make

examples/plugin/plugin/CMakeFiles/example_plugin.dir/tracer.cc.o: examples/plugin/plugin/CMakeFiles/example_plugin.dir/flags.make
examples/plugin/plugin/CMakeFiles/example_plugin.dir/tracer.cc.o: examples/plugin/plugin/tracer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/plugin/plugin/CMakeFiles/example_plugin.dir/tracer.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_plugin.dir/tracer.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/tracer.cc

examples/plugin/plugin/CMakeFiles/example_plugin.dir/tracer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_plugin.dir/tracer.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/tracer.cc > CMakeFiles/example_plugin.dir/tracer.cc.i

examples/plugin/plugin/CMakeFiles/example_plugin.dir/tracer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_plugin.dir/tracer.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/tracer.cc -o CMakeFiles/example_plugin.dir/tracer.cc.s

examples/plugin/plugin/CMakeFiles/example_plugin.dir/factory_impl.cc.o: examples/plugin/plugin/CMakeFiles/example_plugin.dir/flags.make
examples/plugin/plugin/CMakeFiles/example_plugin.dir/factory_impl.cc.o: examples/plugin/plugin/factory_impl.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/plugin/plugin/CMakeFiles/example_plugin.dir/factory_impl.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_plugin.dir/factory_impl.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/factory_impl.cc

examples/plugin/plugin/CMakeFiles/example_plugin.dir/factory_impl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_plugin.dir/factory_impl.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/factory_impl.cc > CMakeFiles/example_plugin.dir/factory_impl.cc.i

examples/plugin/plugin/CMakeFiles/example_plugin.dir/factory_impl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_plugin.dir/factory_impl.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/factory_impl.cc -o CMakeFiles/example_plugin.dir/factory_impl.cc.s

# Object files for target example_plugin
example_plugin_OBJECTS = \
"CMakeFiles/example_plugin.dir/tracer.cc.o" \
"CMakeFiles/example_plugin.dir/factory_impl.cc.o"

# External object files for target example_plugin
example_plugin_EXTERNAL_OBJECTS =

examples/plugin/plugin/libexample_plugin.dylib: examples/plugin/plugin/CMakeFiles/example_plugin.dir/tracer.cc.o
examples/plugin/plugin/libexample_plugin.dylib: examples/plugin/plugin/CMakeFiles/example_plugin.dir/factory_impl.cc.o
examples/plugin/plugin/libexample_plugin.dylib: examples/plugin/plugin/CMakeFiles/example_plugin.dir/build.make
examples/plugin/plugin/libexample_plugin.dylib: examples/plugin/plugin/CMakeFiles/example_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libexample_plugin.dylib"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_plugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/plugin/plugin/CMakeFiles/example_plugin.dir/build: examples/plugin/plugin/libexample_plugin.dylib

.PHONY : examples/plugin/plugin/CMakeFiles/example_plugin.dir/build

examples/plugin/plugin/CMakeFiles/example_plugin.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin && $(CMAKE_COMMAND) -P CMakeFiles/example_plugin.dir/cmake_clean.cmake
.PHONY : examples/plugin/plugin/CMakeFiles/example_plugin.dir/clean

examples/plugin/plugin/CMakeFiles/example_plugin.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/examples/plugin/plugin/CMakeFiles/example_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/plugin/plugin/CMakeFiles/example_plugin.dir/depend

