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
CMAKE_SOURCE_DIR = /home/darkey/CLionProjects/BigIntOpt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darkey/CLionProjects/BigIntOpt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BigIntOpt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BigIntOpt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigIntOpt.dir/flags.make

CMakeFiles/BigIntOpt.dir/main.cpp.o: CMakeFiles/BigIntOpt.dir/flags.make
CMakeFiles/BigIntOpt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darkey/CLionProjects/BigIntOpt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigIntOpt.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BigIntOpt.dir/main.cpp.o -c /home/darkey/CLionProjects/BigIntOpt/main.cpp

CMakeFiles/BigIntOpt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigIntOpt.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darkey/CLionProjects/BigIntOpt/main.cpp > CMakeFiles/BigIntOpt.dir/main.cpp.i

CMakeFiles/BigIntOpt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigIntOpt.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darkey/CLionProjects/BigIntOpt/main.cpp -o CMakeFiles/BigIntOpt.dir/main.cpp.s

CMakeFiles/BigIntOpt.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/BigIntOpt.dir/main.cpp.o.requires

CMakeFiles/BigIntOpt.dir/main.cpp.o.provides: CMakeFiles/BigIntOpt.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BigIntOpt.dir/build.make CMakeFiles/BigIntOpt.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BigIntOpt.dir/main.cpp.o.provides

CMakeFiles/BigIntOpt.dir/main.cpp.o.provides.build: CMakeFiles/BigIntOpt.dir/main.cpp.o


CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o: CMakeFiles/BigIntOpt.dir/flags.make
CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o: ../BigInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darkey/CLionProjects/BigIntOpt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o -c /home/darkey/CLionProjects/BigIntOpt/BigInteger.cpp

CMakeFiles/BigIntOpt.dir/BigInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigIntOpt.dir/BigInteger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darkey/CLionProjects/BigIntOpt/BigInteger.cpp > CMakeFiles/BigIntOpt.dir/BigInteger.cpp.i

CMakeFiles/BigIntOpt.dir/BigInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigIntOpt.dir/BigInteger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darkey/CLionProjects/BigIntOpt/BigInteger.cpp -o CMakeFiles/BigIntOpt.dir/BigInteger.cpp.s

CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.requires:

.PHONY : CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.requires

CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.provides: CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.requires
	$(MAKE) -f CMakeFiles/BigIntOpt.dir/build.make CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.provides.build
.PHONY : CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.provides

CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.provides.build: CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o


# Object files for target BigIntOpt
BigIntOpt_OBJECTS = \
"CMakeFiles/BigIntOpt.dir/main.cpp.o" \
"CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o"

# External object files for target BigIntOpt
BigIntOpt_EXTERNAL_OBJECTS =

BigIntOpt: CMakeFiles/BigIntOpt.dir/main.cpp.o
BigIntOpt: CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o
BigIntOpt: CMakeFiles/BigIntOpt.dir/build.make
BigIntOpt: CMakeFiles/BigIntOpt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darkey/CLionProjects/BigIntOpt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BigIntOpt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigIntOpt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigIntOpt.dir/build: BigIntOpt

.PHONY : CMakeFiles/BigIntOpt.dir/build

CMakeFiles/BigIntOpt.dir/requires: CMakeFiles/BigIntOpt.dir/main.cpp.o.requires
CMakeFiles/BigIntOpt.dir/requires: CMakeFiles/BigIntOpt.dir/BigInteger.cpp.o.requires

.PHONY : CMakeFiles/BigIntOpt.dir/requires

CMakeFiles/BigIntOpt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BigIntOpt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BigIntOpt.dir/clean

CMakeFiles/BigIntOpt.dir/depend:
	cd /home/darkey/CLionProjects/BigIntOpt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darkey/CLionProjects/BigIntOpt /home/darkey/CLionProjects/BigIntOpt /home/darkey/CLionProjects/BigIntOpt/cmake-build-debug /home/darkey/CLionProjects/BigIntOpt/cmake-build-debug /home/darkey/CLionProjects/BigIntOpt/cmake-build-debug/CMakeFiles/BigIntOpt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigIntOpt.dir/depend

