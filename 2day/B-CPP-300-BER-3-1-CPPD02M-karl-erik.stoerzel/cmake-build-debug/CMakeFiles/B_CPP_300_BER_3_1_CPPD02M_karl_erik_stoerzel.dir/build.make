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
CMAKE_COMMAND = /home/CookiieZ/Downloads/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/CookiieZ/Downloads/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/flags.make

CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.o: CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/flags.make
CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.o: ../ex05/ptr_tricks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.o   -c /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/ex05/ptr_tricks.c

CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/ex05/ptr_tricks.c > CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.i

CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/ex05/ptr_tricks.c -o CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.s

# Object files for target B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel_OBJECTS = \
"CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.o"

# External object files for target B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel
B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel_EXTERNAL_OBJECTS =

B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel: CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/ex05/ptr_tricks.c.o
B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel: CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/build.make
B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel: CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/build: B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel

.PHONY : CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/build

CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/clean

CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/depend:
	cd /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug /home/CookiieZ/Epitech/tek2/2day/B-CPP-300-BER-3-1-CPPD02M-karl-erik.stoerzel/cmake-build-debug/CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B_CPP_300_BER_3_1_CPPD02M_karl_erik_stoerzel.dir/depend

