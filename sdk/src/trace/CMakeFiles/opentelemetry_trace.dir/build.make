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
include sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/depend.make

# Include the progress variables for this target.
include sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.o: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.o: sdk/src/trace/tracer_provider.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/tracer_provider.cc

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/tracer_provider.cc > CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.i

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/tracer_provider.cc -o CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.s

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer.cc.o: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer.cc.o: sdk/src/trace/tracer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_trace.dir/tracer.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/tracer.cc

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_trace.dir/tracer.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/tracer.cc > CMakeFiles/opentelemetry_trace.dir/tracer.cc.i

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_trace.dir/tracer.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/tracer.cc -o CMakeFiles/opentelemetry_trace.dir/tracer.cc.s

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/span.cc.o: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/span.cc.o: sdk/src/trace/span.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/span.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_trace.dir/span.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/span.cc

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/span.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_trace.dir/span.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/span.cc > CMakeFiles/opentelemetry_trace.dir/span.cc.i

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/span.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_trace.dir/span.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/span.cc -o CMakeFiles/opentelemetry_trace.dir/span.cc.s

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.o: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.o: sdk/src/trace/batch_span_processor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/batch_span_processor.cc

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/batch_span_processor.cc > CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.i

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/batch_span_processor.cc -o CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.s

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.o: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.o: sdk/src/trace/samplers/parent.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/samplers/parent.cc

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/samplers/parent.cc > CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.i

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/samplers/parent.cc -o CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.s

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.o: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/flags.make
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.o: sdk/src/trace/samplers/trace_id_ratio.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/samplers/trace_id_ratio.cc

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/samplers/trace_id_ratio.cc > CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.i

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/samplers/trace_id_ratio.cc -o CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.s

# Object files for target opentelemetry_trace
opentelemetry_trace_OBJECTS = \
"CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.o" \
"CMakeFiles/opentelemetry_trace.dir/tracer.cc.o" \
"CMakeFiles/opentelemetry_trace.dir/span.cc.o" \
"CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.o" \
"CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.o" \
"CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.o"

# External object files for target opentelemetry_trace
opentelemetry_trace_EXTERNAL_OBJECTS =

sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer_provider.cc.o
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/tracer.cc.o
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/span.cc.o
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/batch_span_processor.cc.o
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/parent.cc.o
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/samplers/trace_id_ratio.cc.o
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/build.make
sdk/src/trace/libopentelemetry_trace.a: sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libopentelemetry_trace.a"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && $(CMAKE_COMMAND) -P CMakeFiles/opentelemetry_trace.dir/cmake_clean_target.cmake
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opentelemetry_trace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/build: sdk/src/trace/libopentelemetry_trace.a

.PHONY : sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/build

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace && $(CMAKE_COMMAND) -P CMakeFiles/opentelemetry_trace.dir/cmake_clean.cmake
.PHONY : sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/clean

sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/src/trace/CMakeFiles/opentelemetry_trace.dir/depend

