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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Collin\CLionProjects\IMUTracking2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IMUTracking2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/IMUTracking2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IMUTracking2.dir/flags.make

CMakeFiles/IMUTracking2.dir/main.cpp.obj: CMakeFiles/IMUTracking2.dir/flags.make
CMakeFiles/IMUTracking2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IMUTracking2.dir/main.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IMUTracking2.dir\main.cpp.obj -c C:\Users\Collin\CLionProjects\IMUTracking2\main.cpp

CMakeFiles/IMUTracking2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMUTracking2.dir/main.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Collin\CLionProjects\IMUTracking2\main.cpp > CMakeFiles\IMUTracking2.dir\main.cpp.i

CMakeFiles/IMUTracking2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMUTracking2.dir/main.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Collin\CLionProjects\IMUTracking2\main.cpp -o CMakeFiles\IMUTracking2.dir\main.cpp.s

CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.obj: CMakeFiles/IMUTracking2.dir/flags.make
CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.obj: ../MathStuff/Vector3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IMUTracking2.dir\MathStuff\Vector3.cpp.obj -c C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Vector3.cpp

CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Vector3.cpp > CMakeFiles\IMUTracking2.dir\MathStuff\Vector3.cpp.i

CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Vector3.cpp -o CMakeFiles\IMUTracking2.dir\MathStuff\Vector3.cpp.s

CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.obj: CMakeFiles/IMUTracking2.dir/flags.make
CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.obj: ../MathStuff/Quaternion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IMUTracking2.dir\MathStuff\Quaternion.cpp.obj -c C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Quaternion.cpp

CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Quaternion.cpp > CMakeFiles\IMUTracking2.dir\MathStuff\Quaternion.cpp.i

CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Quaternion.cpp -o CMakeFiles\IMUTracking2.dir\MathStuff\Quaternion.cpp.s

CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.obj: CMakeFiles/IMUTracking2.dir/flags.make
CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.obj: ../MathStuff/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IMUTracking2.dir\MathStuff\Matrix.cpp.obj -c C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Matrix.cpp

CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Matrix.cpp > CMakeFiles\IMUTracking2.dir\MathStuff\Matrix.cpp.i

CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Collin\CLionProjects\IMUTracking2\MathStuff\Matrix.cpp -o CMakeFiles\IMUTracking2.dir\MathStuff\Matrix.cpp.s

CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.obj: CMakeFiles/IMUTracking2.dir/flags.make
CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.obj: ../Sensors/MagnetometerProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IMUTracking2.dir\Sensors\MagnetometerProcessor.cpp.obj -c C:\Users\Collin\CLionProjects\IMUTracking2\Sensors\MagnetometerProcessor.cpp

CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Collin\CLionProjects\IMUTracking2\Sensors\MagnetometerProcessor.cpp > CMakeFiles\IMUTracking2.dir\Sensors\MagnetometerProcessor.cpp.i

CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Collin\CLionProjects\IMUTracking2\Sensors\MagnetometerProcessor.cpp -o CMakeFiles\IMUTracking2.dir\Sensors\MagnetometerProcessor.cpp.s

# Object files for target IMUTracking2
IMUTracking2_OBJECTS = \
"CMakeFiles/IMUTracking2.dir/main.cpp.obj" \
"CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.obj" \
"CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.obj" \
"CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.obj" \
"CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.obj"

# External object files for target IMUTracking2
IMUTracking2_EXTERNAL_OBJECTS =

IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/main.cpp.obj
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/MathStuff/Vector3.cpp.obj
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/MathStuff/Quaternion.cpp.obj
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/MathStuff/Matrix.cpp.obj
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/Sensors/MagnetometerProcessor.cpp.obj
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/build.make
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/linklibs.rsp
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/objects1.rsp
IMUTracking2.exe: CMakeFiles/IMUTracking2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable IMUTracking2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IMUTracking2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IMUTracking2.dir/build: IMUTracking2.exe
.PHONY : CMakeFiles/IMUTracking2.dir/build

CMakeFiles/IMUTracking2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IMUTracking2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IMUTracking2.dir/clean

CMakeFiles/IMUTracking2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Collin\CLionProjects\IMUTracking2 C:\Users\Collin\CLionProjects\IMUTracking2 C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug C:\Users\Collin\CLionProjects\IMUTracking2\cmake-build-debug\CMakeFiles\IMUTracking2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IMUTracking2.dir/depend
