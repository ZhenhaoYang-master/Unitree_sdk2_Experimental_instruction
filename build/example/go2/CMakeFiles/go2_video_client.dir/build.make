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
CMAKE_SOURCE_DIR = /home/ikun/unitree_sdk2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ikun/unitree_sdk2/build

# Include any dependencies generated for this target.
include example/go2/CMakeFiles/go2_video_client.dir/depend.make

# Include the progress variables for this target.
include example/go2/CMakeFiles/go2_video_client.dir/progress.make

# Include the compile flags for this target's objects.
include example/go2/CMakeFiles/go2_video_client.dir/flags.make

example/go2/CMakeFiles/go2_video_client.dir/go2_video_client.cpp.o: example/go2/CMakeFiles/go2_video_client.dir/flags.make
example/go2/CMakeFiles/go2_video_client.dir/go2_video_client.cpp.o: ../example/go2/go2_video_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ikun/unitree_sdk2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/go2/CMakeFiles/go2_video_client.dir/go2_video_client.cpp.o"
	cd /home/ikun/unitree_sdk2/build/example/go2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/go2_video_client.dir/go2_video_client.cpp.o -c /home/ikun/unitree_sdk2/example/go2/go2_video_client.cpp

example/go2/CMakeFiles/go2_video_client.dir/go2_video_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go2_video_client.dir/go2_video_client.cpp.i"
	cd /home/ikun/unitree_sdk2/build/example/go2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ikun/unitree_sdk2/example/go2/go2_video_client.cpp > CMakeFiles/go2_video_client.dir/go2_video_client.cpp.i

example/go2/CMakeFiles/go2_video_client.dir/go2_video_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go2_video_client.dir/go2_video_client.cpp.s"
	cd /home/ikun/unitree_sdk2/build/example/go2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ikun/unitree_sdk2/example/go2/go2_video_client.cpp -o CMakeFiles/go2_video_client.dir/go2_video_client.cpp.s

# Object files for target go2_video_client
go2_video_client_OBJECTS = \
"CMakeFiles/go2_video_client.dir/go2_video_client.cpp.o"

# External object files for target go2_video_client
go2_video_client_EXTERNAL_OBJECTS =

bin/go2_video_client: example/go2/CMakeFiles/go2_video_client.dir/go2_video_client.cpp.o
bin/go2_video_client: example/go2/CMakeFiles/go2_video_client.dir/build.make
bin/go2_video_client: ../lib/x86_64/libunitree_sdk2.a
bin/go2_video_client: ../thirdparty/lib/x86_64/libddsc.so
bin/go2_video_client: ../thirdparty/lib/x86_64/libddscxx.so
bin/go2_video_client: example/go2/CMakeFiles/go2_video_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ikun/unitree_sdk2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/go2_video_client"
	cd /home/ikun/unitree_sdk2/build/example/go2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/go2_video_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/go2/CMakeFiles/go2_video_client.dir/build: bin/go2_video_client

.PHONY : example/go2/CMakeFiles/go2_video_client.dir/build

example/go2/CMakeFiles/go2_video_client.dir/clean:
	cd /home/ikun/unitree_sdk2/build/example/go2 && $(CMAKE_COMMAND) -P CMakeFiles/go2_video_client.dir/cmake_clean.cmake
.PHONY : example/go2/CMakeFiles/go2_video_client.dir/clean

example/go2/CMakeFiles/go2_video_client.dir/depend:
	cd /home/ikun/unitree_sdk2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ikun/unitree_sdk2 /home/ikun/unitree_sdk2/example/go2 /home/ikun/unitree_sdk2/build /home/ikun/unitree_sdk2/build/example/go2 /home/ikun/unitree_sdk2/build/example/go2/CMakeFiles/go2_video_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/go2/CMakeFiles/go2_video_client.dir/depend

