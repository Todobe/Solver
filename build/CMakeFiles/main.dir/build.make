# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Helti\Desktop\Solver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Helti\Desktop\Solver\build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cpp.obj: ../main.cpp
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Helti\Desktop\Solver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.obj"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.obj -MF CMakeFiles\main.dir\main.cpp.obj.d -o CMakeFiles\main.dir\main.cpp.obj -c C:\Users\Helti\Desktop\Solver\main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Helti\Desktop\Solver\main.cpp > CMakeFiles\main.dir\main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Helti\Desktop\Solver\main.cpp -o CMakeFiles\main.dir\main.cpp.s

CMakeFiles/main.dir/private/graph.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/private/graph.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/private/graph.cpp.obj: ../private/graph.cpp
CMakeFiles/main.dir/private/graph.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Helti\Desktop\Solver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/private/graph.cpp.obj"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/private/graph.cpp.obj -MF CMakeFiles\main.dir\private\graph.cpp.obj.d -o CMakeFiles\main.dir\private\graph.cpp.obj -c C:\Users\Helti\Desktop\Solver\private\graph.cpp

CMakeFiles/main.dir/private/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/private/graph.cpp.i"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Helti\Desktop\Solver\private\graph.cpp > CMakeFiles\main.dir\private\graph.cpp.i

CMakeFiles/main.dir/private/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/private/graph.cpp.s"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Helti\Desktop\Solver\private\graph.cpp -o CMakeFiles\main.dir\private\graph.cpp.s

CMakeFiles/main.dir/private/solver.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/private/solver.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/private/solver.cpp.obj: ../private/solver.cpp
CMakeFiles/main.dir/private/solver.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Helti\Desktop\Solver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/private/solver.cpp.obj"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/private/solver.cpp.obj -MF CMakeFiles\main.dir\private\solver.cpp.obj.d -o CMakeFiles\main.dir\private\solver.cpp.obj -c C:\Users\Helti\Desktop\Solver\private\solver.cpp

CMakeFiles/main.dir/private/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/private/solver.cpp.i"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Helti\Desktop\Solver\private\solver.cpp > CMakeFiles\main.dir\private\solver.cpp.i

CMakeFiles/main.dir/private/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/private/solver.cpp.s"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Helti\Desktop\Solver\private\solver.cpp -o CMakeFiles\main.dir\private\solver.cpp.s

CMakeFiles/main.dir/private/tree.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/private/tree.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/private/tree.cpp.obj: ../private/tree.cpp
CMakeFiles/main.dir/private/tree.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Helti\Desktop\Solver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/private/tree.cpp.obj"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/private/tree.cpp.obj -MF CMakeFiles\main.dir\private\tree.cpp.obj.d -o CMakeFiles\main.dir\private\tree.cpp.obj -c C:\Users\Helti\Desktop\Solver\private\tree.cpp

CMakeFiles/main.dir/private/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/private/tree.cpp.i"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Helti\Desktop\Solver\private\tree.cpp > CMakeFiles\main.dir\private\tree.cpp.i

CMakeFiles/main.dir/private/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/private/tree.cpp.s"
	D:\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Helti\Desktop\Solver\private\tree.cpp -o CMakeFiles\main.dir\private\tree.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.obj" \
"CMakeFiles/main.dir/private/graph.cpp.obj" \
"CMakeFiles/main.dir/private/solver.cpp.obj" \
"CMakeFiles/main.dir/private/tree.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/main.cpp.obj
main.exe: CMakeFiles/main.dir/private/graph.cpp.obj
main.exe: CMakeFiles/main.dir/private/solver.cpp.obj
main.exe: CMakeFiles/main.dir/private/tree.cpp.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: CMakeFiles/main.dir/linklibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Helti\Desktop\Solver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Helti\Desktop\Solver C:\Users\Helti\Desktop\Solver C:\Users\Helti\Desktop\Solver\build C:\Users\Helti\Desktop\Solver\build C:\Users\Helti\Desktop\Solver\build\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
