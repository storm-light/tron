# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joshli/gaims/arcade/tron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joshli/gaims/arcade/tron/build

# Include any dependencies generated for this target.
include source/CMakeFiles/TRON.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/TRON.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/TRON.dir/flags.make

source/CMakeFiles/TRON.dir/functions.cpp.o: source/CMakeFiles/TRON.dir/flags.make
source/CMakeFiles/TRON.dir/functions.cpp.o: ../source/functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshli/gaims/arcade/tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/TRON.dir/functions.cpp.o"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TRON.dir/functions.cpp.o -c /Users/joshli/gaims/arcade/tron/source/functions.cpp

source/CMakeFiles/TRON.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TRON.dir/functions.cpp.i"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshli/gaims/arcade/tron/source/functions.cpp > CMakeFiles/TRON.dir/functions.cpp.i

source/CMakeFiles/TRON.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TRON.dir/functions.cpp.s"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshli/gaims/arcade/tron/source/functions.cpp -o CMakeFiles/TRON.dir/functions.cpp.s

source/CMakeFiles/TRON.dir/gameLoop.cpp.o: source/CMakeFiles/TRON.dir/flags.make
source/CMakeFiles/TRON.dir/gameLoop.cpp.o: ../source/gameLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshli/gaims/arcade/tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/TRON.dir/gameLoop.cpp.o"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TRON.dir/gameLoop.cpp.o -c /Users/joshli/gaims/arcade/tron/source/gameLoop.cpp

source/CMakeFiles/TRON.dir/gameLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TRON.dir/gameLoop.cpp.i"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshli/gaims/arcade/tron/source/gameLoop.cpp > CMakeFiles/TRON.dir/gameLoop.cpp.i

source/CMakeFiles/TRON.dir/gameLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TRON.dir/gameLoop.cpp.s"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshli/gaims/arcade/tron/source/gameLoop.cpp -o CMakeFiles/TRON.dir/gameLoop.cpp.s

source/CMakeFiles/TRON.dir/main.cpp.o: source/CMakeFiles/TRON.dir/flags.make
source/CMakeFiles/TRON.dir/main.cpp.o: ../source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshli/gaims/arcade/tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/CMakeFiles/TRON.dir/main.cpp.o"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TRON.dir/main.cpp.o -c /Users/joshli/gaims/arcade/tron/source/main.cpp

source/CMakeFiles/TRON.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TRON.dir/main.cpp.i"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshli/gaims/arcade/tron/source/main.cpp > CMakeFiles/TRON.dir/main.cpp.i

source/CMakeFiles/TRON.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TRON.dir/main.cpp.s"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshli/gaims/arcade/tron/source/main.cpp -o CMakeFiles/TRON.dir/main.cpp.s

source/CMakeFiles/TRON.dir/player.cpp.o: source/CMakeFiles/TRON.dir/flags.make
source/CMakeFiles/TRON.dir/player.cpp.o: ../source/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshli/gaims/arcade/tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object source/CMakeFiles/TRON.dir/player.cpp.o"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TRON.dir/player.cpp.o -c /Users/joshli/gaims/arcade/tron/source/player.cpp

source/CMakeFiles/TRON.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TRON.dir/player.cpp.i"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshli/gaims/arcade/tron/source/player.cpp > CMakeFiles/TRON.dir/player.cpp.i

source/CMakeFiles/TRON.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TRON.dir/player.cpp.s"
	cd /Users/joshli/gaims/arcade/tron/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshli/gaims/arcade/tron/source/player.cpp -o CMakeFiles/TRON.dir/player.cpp.s

# Object files for target TRON
TRON_OBJECTS = \
"CMakeFiles/TRON.dir/functions.cpp.o" \
"CMakeFiles/TRON.dir/gameLoop.cpp.o" \
"CMakeFiles/TRON.dir/main.cpp.o" \
"CMakeFiles/TRON.dir/player.cpp.o"

# External object files for target TRON
TRON_EXTERNAL_OBJECTS =

source/TRON: source/CMakeFiles/TRON.dir/functions.cpp.o
source/TRON: source/CMakeFiles/TRON.dir/gameLoop.cpp.o
source/TRON: source/CMakeFiles/TRON.dir/main.cpp.o
source/TRON: source/CMakeFiles/TRON.dir/player.cpp.o
source/TRON: source/CMakeFiles/TRON.dir/build.make
source/TRON: source/CMakeFiles/TRON.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/joshli/gaims/arcade/tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TRON"
	cd /Users/joshli/gaims/arcade/tron/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TRON.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/TRON.dir/build: source/TRON

.PHONY : source/CMakeFiles/TRON.dir/build

source/CMakeFiles/TRON.dir/clean:
	cd /Users/joshli/gaims/arcade/tron/build/source && $(CMAKE_COMMAND) -P CMakeFiles/TRON.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/TRON.dir/clean

source/CMakeFiles/TRON.dir/depend:
	cd /Users/joshli/gaims/arcade/tron/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joshli/gaims/arcade/tron /Users/joshli/gaims/arcade/tron/source /Users/joshli/gaims/arcade/tron/build /Users/joshli/gaims/arcade/tron/build/source /Users/joshli/gaims/arcade/tron/build/source/CMakeFiles/TRON.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/TRON.dir/depend
