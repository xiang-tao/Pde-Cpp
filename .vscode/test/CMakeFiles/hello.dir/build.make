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
CMAKE_BINARY_DIR = /home/xt/github/Pde-Cpp/.vscode

# Include any dependencies generated for this target.
include test/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/hello.dir/flags.make

test/CMakeFiles/hello.dir/hello.cpp.o: test/CMakeFiles/hello.dir/flags.make
test/CMakeFiles/hello.dir/hello.cpp.o: ../test/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xt/github/Pde-Cpp/.vscode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/hello.dir/hello.cpp.o"
	cd /home/xt/github/Pde-Cpp/.vscode/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/hello.cpp.o -c /home/xt/github/Pde-Cpp/test/hello.cpp

test/CMakeFiles/hello.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/hello.cpp.i"
	cd /home/xt/github/Pde-Cpp/.vscode/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xt/github/Pde-Cpp/test/hello.cpp > CMakeFiles/hello.dir/hello.cpp.i

test/CMakeFiles/hello.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/hello.cpp.s"
	cd /home/xt/github/Pde-Cpp/.vscode/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xt/github/Pde-Cpp/test/hello.cpp -o CMakeFiles/hello.dir/hello.cpp.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

test/hello: test/CMakeFiles/hello.dir/hello.cpp.o
test/hello: test/CMakeFiles/hello.dir/build.make
test/hello: test/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xt/github/Pde-Cpp/.vscode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello"
	cd /home/xt/github/Pde-Cpp/.vscode/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/hello.dir/build: test/hello

.PHONY : test/CMakeFiles/hello.dir/build

test/CMakeFiles/hello.dir/clean:
	cd /home/xt/github/Pde-Cpp/.vscode/test && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/hello.dir/clean

test/CMakeFiles/hello.dir/depend:
	cd /home/xt/github/Pde-Cpp/.vscode && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xt/github/Pde-Cpp /home/xt/github/Pde-Cpp/test /home/xt/github/Pde-Cpp/.vscode /home/xt/github/Pde-Cpp/.vscode/test /home/xt/github/Pde-Cpp/.vscode/test/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/hello.dir/depend
