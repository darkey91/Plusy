# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/darkey/Clion/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/darkey/Clion/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/darkey/CLionProjects/seg_tree/g

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darkey/CLionProjects/seg_tree/g/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/g.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/g.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/g.dir/flags.make

CMakeFiles/g.dir/main.cpp.o: CMakeFiles/g.dir/flags.make
CMakeFiles/g.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darkey/CLionProjects/seg_tree/g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/g.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/g.dir/main.cpp.o -c /home/darkey/CLionProjects/seg_tree/g/main.cpp

CMakeFiles/g.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darkey/CLionProjects/seg_tree/g/main.cpp > CMakeFiles/g.dir/main.cpp.i

CMakeFiles/g.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darkey/CLionProjects/seg_tree/g/main.cpp -o CMakeFiles/g.dir/main.cpp.s

CMakeFiles/g.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/g.dir/main.cpp.o.requires

CMakeFiles/g.dir/main.cpp.o.provides: CMakeFiles/g.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/g.dir/build.make CMakeFiles/g.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/g.dir/main.cpp.o.provides

CMakeFiles/g.dir/main.cpp.o.provides.build: CMakeFiles/g.dir/main.cpp.o


# Object files for target g
g_OBJECTS = \
"CMakeFiles/g.dir/main.cpp.o"

# External object files for target g
g_EXTERNAL_OBJECTS =

g : CMakeFiles/g.dir/main.cpp.o
g : CMakeFiles/g.dir/build.make
g : CMakeFiles/g.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darkey/CLionProjects/seg_tree/g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable g"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/g.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/g.dir/build: g

.PHONY : CMakeFiles/g.dir/build

CMakeFiles/g.dir/requires: CMakeFiles/g.dir/main.cpp.o.requires

.PHONY : CMakeFiles/g.dir/requires

CMakeFiles/g.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/g.dir/cmake_clean.cmake
.PHONY : CMakeFiles/g.dir/clean

CMakeFiles/g.dir/depend:
	cd /home/darkey/CLionProjects/seg_tree/g/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darkey/CLionProjects/seg_tree/g /home/darkey/CLionProjects/seg_tree/g /home/darkey/CLionProjects/seg_tree/g/cmake-build-debug /home/darkey/CLionProjects/seg_tree/g/cmake-build-debug /home/darkey/CLionProjects/seg_tree/g/cmake-build-debug/CMakeFiles/g.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/g.dir/depend

