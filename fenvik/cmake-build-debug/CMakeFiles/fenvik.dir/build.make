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
CMAKE_SOURCE_DIR = /home/darkey/CLionProjects/fenvik

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darkey/CLionProjects/fenvik/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fenvik.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fenvik.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fenvik.dir/flags.make

CMakeFiles/fenvik.dir/main.cpp.o: CMakeFiles/fenvik.dir/flags.make
CMakeFiles/fenvik.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darkey/CLionProjects/fenvik/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fenvik.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fenvik.dir/main.cpp.o -c /home/darkey/CLionProjects/fenvik/main.cpp

CMakeFiles/fenvik.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fenvik.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darkey/CLionProjects/fenvik/main.cpp > CMakeFiles/fenvik.dir/main.cpp.i

CMakeFiles/fenvik.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fenvik.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darkey/CLionProjects/fenvik/main.cpp -o CMakeFiles/fenvik.dir/main.cpp.s

CMakeFiles/fenvik.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/fenvik.dir/main.cpp.o.requires

CMakeFiles/fenvik.dir/main.cpp.o.provides: CMakeFiles/fenvik.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fenvik.dir/build.make CMakeFiles/fenvik.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/fenvik.dir/main.cpp.o.provides

CMakeFiles/fenvik.dir/main.cpp.o.provides.build: CMakeFiles/fenvik.dir/main.cpp.o


# Object files for target fenvik
fenvik_OBJECTS = \
"CMakeFiles/fenvik.dir/main.cpp.o"

# External object files for target fenvik
fenvik_EXTERNAL_OBJECTS =

fenvik: CMakeFiles/fenvik.dir/main.cpp.o
fenvik: CMakeFiles/fenvik.dir/build.make
fenvik: CMakeFiles/fenvik.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darkey/CLionProjects/fenvik/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fenvik"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fenvik.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fenvik.dir/build: fenvik

.PHONY : CMakeFiles/fenvik.dir/build

CMakeFiles/fenvik.dir/requires: CMakeFiles/fenvik.dir/main.cpp.o.requires

.PHONY : CMakeFiles/fenvik.dir/requires

CMakeFiles/fenvik.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fenvik.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fenvik.dir/clean

CMakeFiles/fenvik.dir/depend:
	cd /home/darkey/CLionProjects/fenvik/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darkey/CLionProjects/fenvik /home/darkey/CLionProjects/fenvik /home/darkey/CLionProjects/fenvik/cmake-build-debug /home/darkey/CLionProjects/fenvik/cmake-build-debug /home/darkey/CLionProjects/fenvik/cmake-build-debug/CMakeFiles/fenvik.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fenvik.dir/depend

