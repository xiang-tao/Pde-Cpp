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
include test/CMakeFiles/qrgivens.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/qrgivens.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/qrgivens.dir/flags.make

test/CMakeFiles/qrgivens.dir/qrgivens.cpp.o: test/CMakeFiles/qrgivens.dir/flags.make
test/CMakeFiles/qrgivens.dir/qrgivens.cpp.o: ../test/qrgivens.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xt/github/Pde-Cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/qrgivens.dir/qrgivens.cpp.o"
	cd /home/xt/github/Pde-Cpp/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qrgivens.dir/qrgivens.cpp.o -c /home/xt/github/Pde-Cpp/test/qrgivens.cpp

test/CMakeFiles/qrgivens.dir/qrgivens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qrgivens.dir/qrgivens.cpp.i"
	cd /home/xt/github/Pde-Cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xt/github/Pde-Cpp/test/qrgivens.cpp > CMakeFiles/qrgivens.dir/qrgivens.cpp.i

test/CMakeFiles/qrgivens.dir/qrgivens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qrgivens.dir/qrgivens.cpp.s"
	cd /home/xt/github/Pde-Cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xt/github/Pde-Cpp/test/qrgivens.cpp -o CMakeFiles/qrgivens.dir/qrgivens.cpp.s

# Object files for target qrgivens
qrgivens_OBJECTS = \
"CMakeFiles/qrgivens.dir/qrgivens.cpp.o"

# External object files for target qrgivens
qrgivens_EXTERNAL_OBJECTS =

test/qrgivens: test/CMakeFiles/qrgivens.dir/qrgivens.cpp.o
test/qrgivens: test/CMakeFiles/qrgivens.dir/build.make
test/qrgivens: test/CMakeFiles/qrgivens.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xt/github/Pde-Cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable qrgivens"
	cd /home/xt/github/Pde-Cpp/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qrgivens.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/qrgivens.dir/build: test/qrgivens

.PHONY : test/CMakeFiles/qrgivens.dir/build

test/CMakeFiles/qrgivens.dir/clean:
	cd /home/xt/github/Pde-Cpp/build/test && $(CMAKE_COMMAND) -P CMakeFiles/qrgivens.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/qrgivens.dir/clean

test/CMakeFiles/qrgivens.dir/depend:
	cd /home/xt/github/Pde-Cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xt/github/Pde-Cpp /home/xt/github/Pde-Cpp/test /home/xt/github/Pde-Cpp/build /home/xt/github/Pde-Cpp/build/test /home/xt/github/Pde-Cpp/build/test/CMakeFiles/qrgivens.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/qrgivens.dir/depend
