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
CMAKE_SOURCE_DIR = /home/forest/gitreps/labs-trubnikov/hw-02_huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/forest/gitreps/labs-trubnikov/hw-02_huffman

# Include any dependencies generated for this target.
include CMakeFiles/hw-02_huffman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw-02_huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw-02_huffman.dir/flags.make

CMakeFiles/hw-02_huffman.dir/src/main.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/main.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/main.cpp

CMakeFiles/hw-02_huffman.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/main.cpp > CMakeFiles/hw-02_huffman.dir/src/main.cpp.i

CMakeFiles/hw-02_huffman.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/main.cpp -o CMakeFiles/hw-02_huffman.dir/src/main.cpp.s

CMakeFiles/hw-02_huffman.dir/src/archive.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/archive.cpp.o: src/archive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/archive.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/archive.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/archive.cpp

CMakeFiles/hw-02_huffman.dir/src/archive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/archive.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/archive.cpp > CMakeFiles/hw-02_huffman.dir/src/archive.cpp.i

CMakeFiles/hw-02_huffman.dir/src/archive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/archive.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/archive.cpp -o CMakeFiles/hw-02_huffman.dir/src/archive.cpp.s

CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.o: src/boolio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/boolio.cpp

CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/boolio.cpp > CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.i

CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/boolio.cpp -o CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.s

CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.o: src/decoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/decoder.cpp

CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/decoder.cpp > CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.i

CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/decoder.cpp -o CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.s

CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.o: src/encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/encoder.cpp

CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/encoder.cpp > CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.i

CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/encoder.cpp -o CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.s

CMakeFiles/hw-02_huffman.dir/src/flags.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/flags.cpp.o: src/flags.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/flags.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/flags.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/flags.cpp

CMakeFiles/hw-02_huffman.dir/src/flags.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/flags.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/flags.cpp > CMakeFiles/hw-02_huffman.dir/src/flags.cpp.i

CMakeFiles/hw-02_huffman.dir/src/flags.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/flags.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/flags.cpp -o CMakeFiles/hw-02_huffman.dir/src/flags.cpp.s

CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.o: CMakeFiles/hw-02_huffman.dir/flags.make
CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.o: src/huffman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.o -c /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/huffman.cpp

CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/huffman.cpp > CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.i

CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forest/gitreps/labs-trubnikov/hw-02_huffman/src/huffman.cpp -o CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.s

# Object files for target hw-02_huffman
hw__02_huffman_OBJECTS = \
"CMakeFiles/hw-02_huffman.dir/src/main.cpp.o" \
"CMakeFiles/hw-02_huffman.dir/src/archive.cpp.o" \
"CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.o" \
"CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.o" \
"CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.o" \
"CMakeFiles/hw-02_huffman.dir/src/flags.cpp.o" \
"CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.o"

# External object files for target hw-02_huffman
hw__02_huffman_EXTERNAL_OBJECTS =

hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/main.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/archive.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/boolio.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/decoder.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/encoder.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/flags.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/src/huffman.cpp.o
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/build.make
hw-02_huffman: CMakeFiles/hw-02_huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable hw-02_huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw-02_huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw-02_huffman.dir/build: hw-02_huffman

.PHONY : CMakeFiles/hw-02_huffman.dir/build

CMakeFiles/hw-02_huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw-02_huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw-02_huffman.dir/clean

CMakeFiles/hw-02_huffman.dir/depend:
	cd /home/forest/gitreps/labs-trubnikov/hw-02_huffman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/forest/gitreps/labs-trubnikov/hw-02_huffman /home/forest/gitreps/labs-trubnikov/hw-02_huffman /home/forest/gitreps/labs-trubnikov/hw-02_huffman /home/forest/gitreps/labs-trubnikov/hw-02_huffman /home/forest/gitreps/labs-trubnikov/hw-02_huffman/CMakeFiles/hw-02_huffman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw-02_huffman.dir/depend

