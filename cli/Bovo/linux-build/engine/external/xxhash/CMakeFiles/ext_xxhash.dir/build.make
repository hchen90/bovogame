# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pat/Projects/Game/bovo/cli/Bovo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pat/Projects/Game/bovo/cli/Bovo/linux-build

# Include any dependencies generated for this target.
include engine/external/xxhash/CMakeFiles/ext_xxhash.dir/depend.make

# Include the progress variables for this target.
include engine/external/xxhash/CMakeFiles/ext_xxhash.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/xxhash/CMakeFiles/ext_xxhash.dir/flags.make

engine/external/xxhash/CMakeFiles/ext_xxhash.dir/xxhash.c.o: engine/external/xxhash/CMakeFiles/ext_xxhash.dir/flags.make
engine/external/xxhash/CMakeFiles/ext_xxhash.dir/xxhash.c.o: ../cocos2d/external/xxhash/xxhash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pat/Projects/Game/bovo/cli/Bovo/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object engine/external/xxhash/CMakeFiles/ext_xxhash.dir/xxhash.c.o"
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ext_xxhash.dir/xxhash.c.o   -c /home/pat/Projects/Game/bovo/cli/Bovo/cocos2d/external/xxhash/xxhash.c

engine/external/xxhash/CMakeFiles/ext_xxhash.dir/xxhash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ext_xxhash.dir/xxhash.c.i"
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pat/Projects/Game/bovo/cli/Bovo/cocos2d/external/xxhash/xxhash.c > CMakeFiles/ext_xxhash.dir/xxhash.c.i

engine/external/xxhash/CMakeFiles/ext_xxhash.dir/xxhash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ext_xxhash.dir/xxhash.c.s"
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pat/Projects/Game/bovo/cli/Bovo/cocos2d/external/xxhash/xxhash.c -o CMakeFiles/ext_xxhash.dir/xxhash.c.s

# Object files for target ext_xxhash
ext_xxhash_OBJECTS = \
"CMakeFiles/ext_xxhash.dir/xxhash.c.o"

# External object files for target ext_xxhash
ext_xxhash_EXTERNAL_OBJECTS =

lib/libext_xxhash.a: engine/external/xxhash/CMakeFiles/ext_xxhash.dir/xxhash.c.o
lib/libext_xxhash.a: engine/external/xxhash/CMakeFiles/ext_xxhash.dir/build.make
lib/libext_xxhash.a: engine/external/xxhash/CMakeFiles/ext_xxhash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pat/Projects/Game/bovo/cli/Bovo/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../lib/libext_xxhash.a"
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash && $(CMAKE_COMMAND) -P CMakeFiles/ext_xxhash.dir/cmake_clean_target.cmake
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ext_xxhash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/xxhash/CMakeFiles/ext_xxhash.dir/build: lib/libext_xxhash.a

.PHONY : engine/external/xxhash/CMakeFiles/ext_xxhash.dir/build

engine/external/xxhash/CMakeFiles/ext_xxhash.dir/clean:
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash && $(CMAKE_COMMAND) -P CMakeFiles/ext_xxhash.dir/cmake_clean.cmake
.PHONY : engine/external/xxhash/CMakeFiles/ext_xxhash.dir/clean

engine/external/xxhash/CMakeFiles/ext_xxhash.dir/depend:
	cd /home/pat/Projects/Game/bovo/cli/Bovo/linux-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pat/Projects/Game/bovo/cli/Bovo /home/pat/Projects/Game/bovo/cli/Bovo/cocos2d/external/xxhash /home/pat/Projects/Game/bovo/cli/Bovo/linux-build /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash /home/pat/Projects/Game/bovo/cli/Bovo/linux-build/engine/external/xxhash/CMakeFiles/ext_xxhash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/xxhash/CMakeFiles/ext_xxhash.dir/depend

