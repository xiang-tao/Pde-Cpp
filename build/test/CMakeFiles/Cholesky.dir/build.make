# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/xt/github/Pde-Cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xt/github/Pde-Cpp/build

# Include any dependencies generated for this target.
include test/CMakeFiles/Cholesky.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Cholesky.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Cholesky.dir/flags.make

test/CMakeFiles/Cholesky.dir/Cholesky.cpp.o: test/CMakeFiles/Cholesky.dir/flags.make
test/CMakeFiles/Cholesky.dir/Cholesky.cpp.o: ../test/Cholesky.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xt/github/Pde-Cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Cholesky.dir/Cholesky.cpp.o"
	cd /home/xt/github/Pde-Cpp/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Cholesky.dir/Cholesky.cpp.o -c /home/xt/github/Pde-Cpp/test/Cholesky.cpp

test/CMakeFiles/Cholesky.dir/Cholesky.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cholesky.dir/Cholesky.cpp.i"
	cd /home/xt/github/Pde-Cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xt/github/Pde-Cpp/test/Cholesky.cpp > CMakeFiles/Cholesky.dir/Cholesky.cpp.i

test/CMakeFiles/Cholesky.dir/Cholesky.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cholesky.dir/Cholesky.cpp.s"
	cd /home/xt/github/Pde-Cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xt/github/Pde-Cpp/test/Cholesky.cpp -o CMakeFiles/Cholesky.dir/Cholesky.cpp.s

# Object files for target Cholesky
Cholesky_OBJECTS = \
"CMakeFiles/Cholesky.dir/Cholesky.cpp.o"

# External object files for target Cholesky
Cholesky_EXTERNAL_OBJECTS =

test/Cholesky: test/CMakeFiles/Cholesky.dir/Cholesky.cpp.o
test/Cholesky: test/CMakeFiles/Cholesky.dir/build.make
test/Cholesky: test/CMakeFiles/Cholesky.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xt/github/Pde-Cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cholesky"
	cd /home/xt/github/Pde-Cpp/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cholesky.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/Cholesky.dir/build: test/Cholesky

.PHONY : test/CMakeFiles/Cholesky.dir/build

test/CMakeFiles/Cholesky.dir/clean:
	cd /home/xt/github/Pde-Cpp/build/test && $(CMAKE_COMMAND) -P CMakeFiles/Cholesky.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Cholesky.dir/clean

test/CMakeFiles/Cholesky.dir/depend:
	cd /home/xt/github/Pde-Cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xt/github/Pde-Cpp /home/xt/github/Pde-Cpp/test /home/xt/github/Pde-Cpp/build /home/xt/github/Pde-Cpp/build/test /home/xt/github/Pde-Cpp/build/test/CMakeFiles/Cholesky.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Cholesky.dir/depend

