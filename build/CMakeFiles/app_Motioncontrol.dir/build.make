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
include CMakeFiles/app_Motioncontrol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app_Motioncontrol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app_Motioncontrol.dir/flags.make

CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.o: CMakeFiles/app_Motioncontrol.dir/flags.make
CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.o: ../example/user/app_Motioncontrol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ikun/unitree_sdk2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.o -c /home/ikun/unitree_sdk2/example/user/app_Motioncontrol.cpp

CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ikun/unitree_sdk2/example/user/app_Motioncontrol.cpp > CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.i

CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ikun/unitree_sdk2/example/user/app_Motioncontrol.cpp -o CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.s

# Object files for target app_Motioncontrol
app_Motioncontrol_OBJECTS = \
"CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.o"

# External object files for target app_Motioncontrol
app_Motioncontrol_EXTERNAL_OBJECTS =

bin/app_Motioncontrol: CMakeFiles/app_Motioncontrol.dir/example/user/app_Motioncontrol.cpp.o
bin/app_Motioncontrol: CMakeFiles/app_Motioncontrol.dir/build.make
bin/app_Motioncontrol: ../lib/x86_64/libunitree_sdk2.a
bin/app_Motioncontrol: ../thirdparty/lib/x86_64/libddsc.so
bin/app_Motioncontrol: ../thirdparty/lib/x86_64/libddscxx.so
bin/app_Motioncontrol: CMakeFiles/app_Motioncontrol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ikun/unitree_sdk2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/app_Motioncontrol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app_Motioncontrol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app_Motioncontrol.dir/build: bin/app_Motioncontrol

.PHONY : CMakeFiles/app_Motioncontrol.dir/build

CMakeFiles/app_Motioncontrol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app_Motioncontrol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app_Motioncontrol.dir/clean

CMakeFiles/app_Motioncontrol.dir/depend:
	cd /home/ikun/unitree_sdk2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ikun/unitree_sdk2 /home/ikun/unitree_sdk2 /home/ikun/unitree_sdk2/build /home/ikun/unitree_sdk2/build /home/ikun/unitree_sdk2/build/CMakeFiles/app_Motioncontrol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app_Motioncontrol.dir/depend

