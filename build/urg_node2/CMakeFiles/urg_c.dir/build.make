# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ywen/tas2-software/src/urg_node2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ywen/tas2-software/build/urg_node2

# Include any dependencies generated for this target.
include CMakeFiles/urg_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/urg_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/urg_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/urg_c.dir/flags.make

CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_sensor.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_sensor.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_sensor.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_sensor.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_utils.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_utils.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_utils.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_utils.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_debug.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_debug.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_debug.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_debug.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_connection.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_connection.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_connection.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_connection.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_ring_buffer.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_ring_buffer.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_ring_buffer.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_ring_buffer.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial_utils.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial_utils.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial_utils.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_serial_utils.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.s

CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o: CMakeFiles/urg_c.dir/flags.make
CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o: /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_tcpclient.c
CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o: CMakeFiles/urg_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o -MF CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o.d -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o -c /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_tcpclient.c

CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_tcpclient.c > CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.i

CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ywen/tas2-software/src/urg_node2/urg_library/current/src/urg_tcpclient.c -o CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.s

# Object files for target urg_c
urg_c_OBJECTS = \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o" \
"CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o"

# External object files for target urg_c
urg_c_EXTERNAL_OBJECTS =

liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_sensor.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_utils.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_debug.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_connection.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_ring_buffer.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_serial_utils.c.o
liburg_c.so: CMakeFiles/urg_c.dir/urg_library/current/src/urg_tcpclient.c.o
liburg_c.so: CMakeFiles/urg_c.dir/build.make
liburg_c.so: CMakeFiles/urg_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ywen/tas2-software/build/urg_node2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C shared library liburg_c.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/urg_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/urg_c.dir/build: liburg_c.so
.PHONY : CMakeFiles/urg_c.dir/build

CMakeFiles/urg_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/urg_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/urg_c.dir/clean

CMakeFiles/urg_c.dir/depend:
	cd /home/ywen/tas2-software/build/urg_node2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ywen/tas2-software/src/urg_node2 /home/ywen/tas2-software/src/urg_node2 /home/ywen/tas2-software/build/urg_node2 /home/ywen/tas2-software/build/urg_node2 /home/ywen/tas2-software/build/urg_node2/CMakeFiles/urg_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/urg_c.dir/depend

