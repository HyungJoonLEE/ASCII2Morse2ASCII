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

# Include any dependencies generated for this target.
include src/CMakeFiles/morse2ascii.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/morse2ascii.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/morse2ascii.dir/flags.make

src/CMakeFiles/morse2ascii.dir/common.c.o: src/CMakeFiles/morse2ascii.dir/flags.make
src/CMakeFiles/morse2ascii.dir/common.c.o: ../src/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klaiden/Desktop/work/assign1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/morse2ascii.dir/common.c.o"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && /usr/local/Cellar/gcc/11.2.0/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/morse2ascii.dir/common.c.o -c /Users/klaiden/Desktop/work/assign1/src/common.c

src/CMakeFiles/morse2ascii.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/morse2ascii.dir/common.c.i"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && /usr/local/Cellar/gcc/11.2.0/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/klaiden/Desktop/work/assign1/src/common.c > CMakeFiles/morse2ascii.dir/common.c.i

src/CMakeFiles/morse2ascii.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/morse2ascii.dir/common.c.s"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && /usr/local/Cellar/gcc/11.2.0/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/klaiden/Desktop/work/assign1/src/common.c -o CMakeFiles/morse2ascii.dir/common.c.s

src/CMakeFiles/morse2ascii.dir/morse2ascii.c.o: src/CMakeFiles/morse2ascii.dir/flags.make
src/CMakeFiles/morse2ascii.dir/morse2ascii.c.o: ../src/morse2ascii.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klaiden/Desktop/work/assign1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/morse2ascii.dir/morse2ascii.c.o"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && /usr/local/Cellar/gcc/11.2.0/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/morse2ascii.dir/morse2ascii.c.o -c /Users/klaiden/Desktop/work/assign1/src/morse2ascii.c

src/CMakeFiles/morse2ascii.dir/morse2ascii.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/morse2ascii.dir/morse2ascii.c.i"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && /usr/local/Cellar/gcc/11.2.0/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/klaiden/Desktop/work/assign1/src/morse2ascii.c > CMakeFiles/morse2ascii.dir/morse2ascii.c.i

src/CMakeFiles/morse2ascii.dir/morse2ascii.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/morse2ascii.dir/morse2ascii.c.s"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && /usr/local/Cellar/gcc/11.2.0/bin/gcc-11 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/klaiden/Desktop/work/assign1/src/morse2ascii.c -o CMakeFiles/morse2ascii.dir/morse2ascii.c.s

# Object files for target morse2ascii
morse2ascii_OBJECTS = \
"CMakeFiles/morse2ascii.dir/common.c.o" \
"CMakeFiles/morse2ascii.dir/morse2ascii.c.o"

# External object files for target morse2ascii
morse2ascii_EXTERNAL_OBJECTS =

src/morse2ascii: src/CMakeFiles/morse2ascii.dir/common.c.o
src/morse2ascii: src/CMakeFiles/morse2ascii.dir/morse2ascii.c.o
src/morse2ascii: src/CMakeFiles/morse2ascii.dir/build.make
src/morse2ascii: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.0.sdk/usr/lib/libm.tbd
src/morse2ascii: /usr/local/lib/libdc_error.dylib
src/morse2ascii: /usr/local/lib/libdc_posix.dylib
src/morse2ascii: /usr/local/lib/libdc_util.dylib
src/morse2ascii: /usr/local/lib/libdc_fsm.dylib
src/morse2ascii: /usr/local/lib/libdc_application.dylib
src/morse2ascii: src/CMakeFiles/morse2ascii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/klaiden/Desktop/work/assign1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable morse2ascii"
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/morse2ascii.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/morse2ascii.dir/build: src/morse2ascii
.PHONY : src/CMakeFiles/morse2ascii.dir/build

src/CMakeFiles/morse2ascii.dir/clean:
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/morse2ascii.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/morse2ascii.dir/clean

src/CMakeFiles/morse2ascii.dir/depend:
	cd /Users/klaiden/Desktop/work/assign1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/klaiden/Desktop/work/assign1 /Users/klaiden/Desktop/work/assign1/src /Users/klaiden/Desktop/work/assign1/cmake-build-debug /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src /Users/klaiden/Desktop/work/assign1/cmake-build-debug/src/CMakeFiles/morse2ascii.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/morse2ascii.dir/depend

