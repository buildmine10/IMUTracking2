cmake_minimum_required(VERSION 3.20)
project(IMUTracking2)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMUTracking2 main.cpp  MathStuff/Vector3.cpp MathStuff/Vector3.h MathStuff/Quaternion.cpp MathStuff/Quaternion.h MathStuff/Matrix.cpp MathStuff/Matrix.h Sensors/MagnetometerProcessor.cpp Sensors/MagnetometerProcessor.h)
