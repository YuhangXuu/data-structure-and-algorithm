# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/xuyuhang/Desktop/Programming class/Class1/codes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/codes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/codes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/codes.dir/flags.make

CMakeFiles/codes.dir/SortingAlgorithm.cpp.o: CMakeFiles/codes.dir/flags.make
CMakeFiles/codes.dir/SortingAlgorithm.cpp.o: ../SortingAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/codes.dir/SortingAlgorithm.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codes.dir/SortingAlgorithm.cpp.o -c "/Users/xuyuhang/Desktop/Programming class/Class1/codes/SortingAlgorithm.cpp"

CMakeFiles/codes.dir/SortingAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codes.dir/SortingAlgorithm.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xuyuhang/Desktop/Programming class/Class1/codes/SortingAlgorithm.cpp" > CMakeFiles/codes.dir/SortingAlgorithm.cpp.i

CMakeFiles/codes.dir/SortingAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codes.dir/SortingAlgorithm.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xuyuhang/Desktop/Programming class/Class1/codes/SortingAlgorithm.cpp" -o CMakeFiles/codes.dir/SortingAlgorithm.cpp.s

# Object files for target codes
codes_OBJECTS = \
"CMakeFiles/codes.dir/SortingAlgorithm.cpp.o"

# External object files for target codes
codes_EXTERNAL_OBJECTS =

codes: CMakeFiles/codes.dir/SortingAlgorithm.cpp.o
codes: CMakeFiles/codes.dir/build.make
codes: CMakeFiles/codes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/codes.dir/build: codes

.PHONY : CMakeFiles/codes.dir/build

CMakeFiles/codes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/codes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/codes.dir/clean

CMakeFiles/codes.dir/depend:
	cd "/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/xuyuhang/Desktop/Programming class/Class1/codes" "/Users/xuyuhang/Desktop/Programming class/Class1/codes" "/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug" "/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug" "/Users/xuyuhang/Desktop/Programming class/Class1/codes/cmake-build-debug/CMakeFiles/codes.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/codes.dir/depend

