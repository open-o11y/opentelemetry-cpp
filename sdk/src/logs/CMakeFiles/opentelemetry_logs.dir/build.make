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
include sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/depend.make

# Include the progress variables for this target.
include sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/flags.make

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.o: sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/flags.make
sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.o: sdk/src/logs/logger_provider.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/logger_provider.cc

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/logger_provider.cc > CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.i

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/logger_provider.cc -o CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.s

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger.cc.o: sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/flags.make
sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger.cc.o: sdk/src/logs/logger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger.cc.o"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opentelemetry_logs.dir/logger.cc.o -c /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/logger.cc

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opentelemetry_logs.dir/logger.cc.i"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/logger.cc > CMakeFiles/opentelemetry_logs.dir/logger.cc.i

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opentelemetry_logs.dir/logger.cc.s"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/logger.cc -o CMakeFiles/opentelemetry_logs.dir/logger.cc.s

# Object files for target opentelemetry_logs
opentelemetry_logs_OBJECTS = \
"CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.o" \
"CMakeFiles/opentelemetry_logs.dir/logger.cc.o"

# External object files for target opentelemetry_logs
opentelemetry_logs_EXTERNAL_OBJECTS =

sdk/src/logs/libopentelemetry_logs.a: sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger_provider.cc.o
sdk/src/logs/libopentelemetry_logs.a: sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/logger.cc.o
sdk/src/logs/libopentelemetry_logs.a: sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/build.make
sdk/src/logs/libopentelemetry_logs.a: sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libopentelemetry_logs.a"
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && $(CMAKE_COMMAND) -P CMakeFiles/opentelemetry_logs.dir/cmake_clean_target.cmake
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opentelemetry_logs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/build: sdk/src/logs/libopentelemetry_logs.a

.PHONY : sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/build

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/clean:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs && $(CMAKE_COMMAND) -P CMakeFiles/opentelemetry_logs.dir/cmake_clean.cmake
.PHONY : sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/clean

sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/depend:
	cd /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs /Users/mseufert/Documents/opentelemetry-cpp-ES-exporter/sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/src/logs/CMakeFiles/opentelemetry_logs.dir/depend

