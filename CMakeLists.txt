cmake_minimum_required(VERSION 3.20)
project(IMUTracking2)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMUTracking2 main.cpp  MathStuff/Vector3.cpp MathStuff/Vector3.h MathStuff/Quaternion.cpp MathStuff/Quaternion.h MathStuff/Matrix.cpp MathStuff/Matrix.h DataLoading/CSVLoader.cpp DataLoading/CSVLoader.h DataLoading/DataLoader.cpp DataLoading/DataLoader.h Sensors/Magnetometer/Magnetometer.cpp Sensors/Magnetometer/Magnetometer.h Sensors/Magnetometer/SimulatedMagnetometer.cpp Sensors/Magnetometer/SimulatedMagnetometer.h Sensors/Accelerometer/Accelerometer.cpp Sensors/Accelerometer/Accelerometer.h Sensors/Accelerometer/SimulatedAccelerometer.cpp Sensors/Accelerometer/SimulatedAccelerometer.h Sensors/Gyroscope/Gyroscope.cpp Sensors/Gyroscope/Gyroscope.h Sensors/Gyroscope/SimulatedGyroscope.cpp Sensors/Gyroscope/SimulatedGyroscope.h)
