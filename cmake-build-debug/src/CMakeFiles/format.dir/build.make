# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/klaiden/Desktop/work/assign1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/klaiden/Desktop/work/assign1/cmake-build-debug

# Utility rule file for format.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/format.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/format.dir/progress.make

src/CMakeFiles/format:
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && clang-format -i /Users/klaiden/Desktop/work/assign1/include/common.h /Users/klaiden/Desktop/work/assign1/src/common.c

format: src/CMakeFiles/format
format: src/CMakeFiles/format.dir/build.make
.PHONY : format

# Rule to build all files generated by this target.
src/CMakeFiles/format.dir/build: format
.PHONY : src/CMakeFiles/format.dir/build

src/CMakeFiles/format.dir/clean:
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/format.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/format.dir/clean

src/CMakeFiles/format.dir/depend:
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/klaiden/Desktop/work/assign1 /Users/klaiden/Desktop/work/assign1/src /Users/klaiden/Desktop/work/assign1/cmake-build-debug /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src/CMakeFiles/format.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/format.dir/depend

