# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/demo

# Include any dependencies generated for this target.
include CMakeFiles/sayhellotolinux.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sayhellotolinux.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sayhellotolinux.dir/flags.make

CMakeFiles/sayhellotolinux.dir/main.cpp.o: CMakeFiles/sayhellotolinux.dir/flags.make
CMakeFiles/sayhellotolinux.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sayhellotolinux.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sayhellotolinux.dir/main.cpp.o -c /home/demo/main.cpp

CMakeFiles/sayhellotolinux.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sayhellotolinux.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/demo/main.cpp > CMakeFiles/sayhellotolinux.dir/main.cpp.i

CMakeFiles/sayhellotolinux.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sayhellotolinux.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/demo/main.cpp -o CMakeFiles/sayhellotolinux.dir/main.cpp.s

CMakeFiles/sayhellotolinux.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/sayhellotolinux.dir/main.cpp.o.requires

CMakeFiles/sayhellotolinux.dir/main.cpp.o.provides: CMakeFiles/sayhellotolinux.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sayhellotolinux.dir/build.make CMakeFiles/sayhellotolinux.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sayhellotolinux.dir/main.cpp.o.provides

CMakeFiles/sayhellotolinux.dir/main.cpp.o.provides.build: CMakeFiles/sayhellotolinux.dir/main.cpp.o


# Object files for target sayhellotolinux
sayhellotolinux_OBJECTS = \
"CMakeFiles/sayhellotolinux.dir/main.cpp.o"

# External object files for target sayhellotolinux
sayhellotolinux_EXTERNAL_OBJECTS =

sayhellotolinux: CMakeFiles/sayhellotolinux.dir/main.cpp.o
sayhellotolinux: CMakeFiles/sayhellotolinux.dir/build.make
sayhellotolinux: CMakeFiles/sayhellotolinux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sayhellotolinux"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sayhellotolinux.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sayhellotolinux.dir/build: sayhellotolinux

.PHONY : CMakeFiles/sayhellotolinux.dir/build

CMakeFiles/sayhellotolinux.dir/requires: CMakeFiles/sayhellotolinux.dir/main.cpp.o.requires

.PHONY : CMakeFiles/sayhellotolinux.dir/requires

CMakeFiles/sayhellotolinux.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sayhellotolinux.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sayhellotolinux.dir/clean

CMakeFiles/sayhellotolinux.dir/depend:
	cd /home/demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/demo /home/demo /home/demo /home/demo /home/demo/CMakeFiles/sayhellotolinux.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sayhellotolinux.dir/depend

