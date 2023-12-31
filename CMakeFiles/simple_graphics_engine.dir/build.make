# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/j00r/simple_graphics_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j00r/simple_graphics_engine

# Include any dependencies generated for this target.
include CMakeFiles/simple_graphics_engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/simple_graphics_engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_graphics_engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_graphics_engine.dir/flags.make

CMakeFiles/simple_graphics_engine.dir/src/animation.c.o: CMakeFiles/simple_graphics_engine.dir/flags.make
CMakeFiles/simple_graphics_engine.dir/src/animation.c.o: src/animation.c
CMakeFiles/simple_graphics_engine.dir/src/animation.c.o: CMakeFiles/simple_graphics_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j00r/simple_graphics_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simple_graphics_engine.dir/src/animation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/simple_graphics_engine.dir/src/animation.c.o -MF CMakeFiles/simple_graphics_engine.dir/src/animation.c.o.d -o CMakeFiles/simple_graphics_engine.dir/src/animation.c.o -c /home/j00r/simple_graphics_engine/src/animation.c

CMakeFiles/simple_graphics_engine.dir/src/animation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_graphics_engine.dir/src/animation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/j00r/simple_graphics_engine/src/animation.c > CMakeFiles/simple_graphics_engine.dir/src/animation.c.i

CMakeFiles/simple_graphics_engine.dir/src/animation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_graphics_engine.dir/src/animation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/j00r/simple_graphics_engine/src/animation.c -o CMakeFiles/simple_graphics_engine.dir/src/animation.c.s

CMakeFiles/simple_graphics_engine.dir/src/main.c.o: CMakeFiles/simple_graphics_engine.dir/flags.make
CMakeFiles/simple_graphics_engine.dir/src/main.c.o: src/main.c
CMakeFiles/simple_graphics_engine.dir/src/main.c.o: CMakeFiles/simple_graphics_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j00r/simple_graphics_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/simple_graphics_engine.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/simple_graphics_engine.dir/src/main.c.o -MF CMakeFiles/simple_graphics_engine.dir/src/main.c.o.d -o CMakeFiles/simple_graphics_engine.dir/src/main.c.o -c /home/j00r/simple_graphics_engine/src/main.c

CMakeFiles/simple_graphics_engine.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_graphics_engine.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/j00r/simple_graphics_engine/src/main.c > CMakeFiles/simple_graphics_engine.dir/src/main.c.i

CMakeFiles/simple_graphics_engine.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_graphics_engine.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/j00r/simple_graphics_engine/src/main.c -o CMakeFiles/simple_graphics_engine.dir/src/main.c.s

CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o: CMakeFiles/simple_graphics_engine.dir/flags.make
CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o: src/vectors.c
CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o: CMakeFiles/simple_graphics_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j00r/simple_graphics_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o -MF CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o.d -o CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o -c /home/j00r/simple_graphics_engine/src/vectors.c

CMakeFiles/simple_graphics_engine.dir/src/vectors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_graphics_engine.dir/src/vectors.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/j00r/simple_graphics_engine/src/vectors.c > CMakeFiles/simple_graphics_engine.dir/src/vectors.c.i

CMakeFiles/simple_graphics_engine.dir/src/vectors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_graphics_engine.dir/src/vectors.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/j00r/simple_graphics_engine/src/vectors.c -o CMakeFiles/simple_graphics_engine.dir/src/vectors.c.s

# Object files for target simple_graphics_engine
simple_graphics_engine_OBJECTS = \
"CMakeFiles/simple_graphics_engine.dir/src/animation.c.o" \
"CMakeFiles/simple_graphics_engine.dir/src/main.c.o" \
"CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o"

# External object files for target simple_graphics_engine
simple_graphics_engine_EXTERNAL_OBJECTS =

simple_graphics_engine: CMakeFiles/simple_graphics_engine.dir/src/animation.c.o
simple_graphics_engine: CMakeFiles/simple_graphics_engine.dir/src/main.c.o
simple_graphics_engine: CMakeFiles/simple_graphics_engine.dir/src/vectors.c.o
simple_graphics_engine: CMakeFiles/simple_graphics_engine.dir/build.make
simple_graphics_engine: /usr/local/lib/libxcb.a
simple_graphics_engine: /usr/lib/libXau.so
simple_graphics_engine: /usr/lib/libXdmcp.so
simple_graphics_engine: CMakeFiles/simple_graphics_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/j00r/simple_graphics_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable simple_graphics_engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_graphics_engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_graphics_engine.dir/build: simple_graphics_engine
.PHONY : CMakeFiles/simple_graphics_engine.dir/build

CMakeFiles/simple_graphics_engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_graphics_engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_graphics_engine.dir/clean

CMakeFiles/simple_graphics_engine.dir/depend:
	cd /home/j00r/simple_graphics_engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j00r/simple_graphics_engine /home/j00r/simple_graphics_engine /home/j00r/simple_graphics_engine /home/j00r/simple_graphics_engine /home/j00r/simple_graphics_engine/CMakeFiles/simple_graphics_engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_graphics_engine.dir/depend

