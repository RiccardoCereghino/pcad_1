# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/rick/CLionProjects/pcad_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rick/CLionProjects/pcad_1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rick/CLionProjects/pcad_1/CMakeFiles /home/rick/CLionProjects/pcad_1/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rick/CLionProjects/pcad_1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named esercizio_2

# Build rule for target.
esercizio_2: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 esercizio_2
.PHONY : esercizio_2

# fast build rule for target.
esercizio_2/fast:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/build
.PHONY : esercizio_2/fast

#=============================================================================
# Target rules for targets named esercizio_1

# Build rule for target.
esercizio_1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 esercizio_1
.PHONY : esercizio_1

# fast build rule for target.
esercizio_1/fast:
	$(MAKE) -f CMakeFiles/esercizio_1.dir/build.make CMakeFiles/esercizio_1.dir/build
.PHONY : esercizio_1/fast

esercizio_1.o: esercizio_1.c.o

.PHONY : esercizio_1.o

# target to build an object file
esercizio_1.c.o:
	$(MAKE) -f CMakeFiles/esercizio_1.dir/build.make CMakeFiles/esercizio_1.dir/esercizio_1.c.o
.PHONY : esercizio_1.c.o

esercizio_1.i: esercizio_1.c.i

.PHONY : esercizio_1.i

# target to preprocess a source file
esercizio_1.c.i:
	$(MAKE) -f CMakeFiles/esercizio_1.dir/build.make CMakeFiles/esercizio_1.dir/esercizio_1.c.i
.PHONY : esercizio_1.c.i

esercizio_1.s: esercizio_1.c.s

.PHONY : esercizio_1.s

# target to generate assembly for a file
esercizio_1.c.s:
	$(MAKE) -f CMakeFiles/esercizio_1.dir/build.make CMakeFiles/esercizio_1.dir/esercizio_1.c.s
.PHONY : esercizio_1.c.s

esercizio_2.o: esercizio_2.c.o

.PHONY : esercizio_2.o

# target to build an object file
esercizio_2.c.o:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/esercizio_2.c.o
.PHONY : esercizio_2.c.o

esercizio_2.i: esercizio_2.c.i

.PHONY : esercizio_2.i

# target to preprocess a source file
esercizio_2.c.i:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/esercizio_2.c.i
.PHONY : esercizio_2.c.i

esercizio_2.s: esercizio_2.c.s

.PHONY : esercizio_2.s

# target to generate assembly for a file
esercizio_2.c.s:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/esercizio_2.c.s
.PHONY : esercizio_2.c.s

matrix/matrix.o: matrix/matrix.c.o

.PHONY : matrix/matrix.o

# target to build an object file
matrix/matrix.c.o:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/matrix/matrix.c.o
.PHONY : matrix/matrix.c.o

matrix/matrix.i: matrix/matrix.c.i

.PHONY : matrix/matrix.i

# target to preprocess a source file
matrix/matrix.c.i:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/matrix/matrix.c.i
.PHONY : matrix/matrix.c.i

matrix/matrix.s: matrix/matrix.c.s

.PHONY : matrix/matrix.s

# target to generate assembly for a file
matrix/matrix.c.s:
	$(MAKE) -f CMakeFiles/esercizio_2.dir/build.make CMakeFiles/esercizio_2.dir/matrix/matrix.c.s
.PHONY : matrix/matrix.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... esercizio_2"
	@echo "... esercizio_1"
	@echo "... esercizio_1.o"
	@echo "... esercizio_1.i"
	@echo "... esercizio_1.s"
	@echo "... esercizio_2.o"
	@echo "... esercizio_2.i"
	@echo "... esercizio_2.s"
	@echo "... matrix/matrix.o"
	@echo "... matrix/matrix.i"
	@echo "... matrix/matrix.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
