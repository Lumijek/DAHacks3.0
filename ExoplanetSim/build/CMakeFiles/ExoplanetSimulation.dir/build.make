# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build

# Include any dependencies generated for this target.
include CMakeFiles/ExoplanetSimulation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ExoplanetSimulation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExoplanetSimulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ExoplanetSimulation.dir/flags.make

CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/main.cpp
CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/main.cpp

CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/main.cpp > CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/main.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Application.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Application.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Application.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Application.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/InputHandler.cpp
CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/InputHandler.cpp

CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/InputHandler.cpp > CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/InputHandler.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Renderer.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Renderer.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Renderer.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Renderer.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/glad.c
CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o -MF CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/glad.c

CMakeFiles/ExoplanetSimulation.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ExoplanetSimulation.dir/src/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/glad.c > CMakeFiles/ExoplanetSimulation.dir/src/glad.c.i

CMakeFiles/ExoplanetSimulation.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ExoplanetSimulation.dir/src/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/glad.c -o CMakeFiles/ExoplanetSimulation.dir/src/glad.c.s

CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Camera.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Camera.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Camera.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Camera.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Skybox.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Skybox.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Skybox.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Skybox.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Shader.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Shader.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Shader.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Shader.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/stb_image.cpp
CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/stb_image.cpp

CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/stb_image.cpp > CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/stb_image.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Star.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Star.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Star.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Star.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Planet.cpp
CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Planet.cpp

CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Planet.cpp > CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/Planet.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.s

CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o: CMakeFiles/ExoplanetSimulation.dir/flags.make
CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o: /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/SphereMesh.cpp
CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o: CMakeFiles/ExoplanetSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o -MF CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o.d -o CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o -c /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/SphereMesh.cpp

CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/SphereMesh.cpp > CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.i

CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/src/SphereMesh.cpp -o CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.s

# Object files for target ExoplanetSimulation
ExoplanetSimulation_OBJECTS = \
"CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o" \
"CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o"

# External object files for target ExoplanetSimulation
ExoplanetSimulation_EXTERNAL_OBJECTS =

ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/main.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Application.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/InputHandler.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Renderer.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/glad.c.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Camera.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Skybox.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Shader.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/stb_image.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Star.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/Planet.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/src/SphereMesh.cpp.o
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/build.make
ExoplanetSimulation: libimgui.a
ExoplanetSimulation: CMakeFiles/ExoplanetSimulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ExoplanetSimulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExoplanetSimulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ExoplanetSimulation.dir/build: ExoplanetSimulation
.PHONY : CMakeFiles/ExoplanetSimulation.dir/build

CMakeFiles/ExoplanetSimulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExoplanetSimulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExoplanetSimulation.dir/clean

CMakeFiles/ExoplanetSimulation.dir/depend:
	cd /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build /Users/cadenpun/Documents/GitHub/DAHacks3.0/ExoplanetSim/build/CMakeFiles/ExoplanetSimulation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ExoplanetSimulation.dir/depend

