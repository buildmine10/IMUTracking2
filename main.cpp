#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

#include "DataLoading/CSVLoader.h"
#include "DataLoading/DataLoader.h"

#include "Sensors/Magnetometer/SimulatedMagnetometer.h"
#include "Sensors/Accelerometer/SimulatedAccelerometer.h"
#include "Sensors/Gyroscope/SimulatedGyroscope.h"

using namespace std::chrono_literals;

int main() {
    auto magCalibrationDataRaw = CSVLoader::loadFile("Magnetometer Calibration Data.csv");
    std::vector<Vector3> magCalibrationData;
    magCalibrationData.reserve(magCalibrationDataRaw.size());
    for(auto n : magCalibrationDataRaw){
        magCalibrationData.emplace_back(n.at(1), n.at(2), n.at(3));
    }


    auto gyroCalibrationDataRaw = CSVLoader::loadFile("Gyro Calibration Data2.csv");
    std::vector<Vector3> gyroCalibrationData;
    gyroCalibrationData.reserve(gyroCalibrationDataRaw.size());
    for(auto n : gyroCalibrationDataRaw){
        gyroCalibrationData.emplace_back(n.at(1), n.at(2), n.at(3));
    }




    //DataLoader data = DataLoader("Stationairy/Accelerometer.csv", "Stationairy/Gyroscope.csv", "Stationairy/Magnetometer.csv");
    DataLoader data = DataLoader("Another90/Accelerometer.csv", "Another90/Gyroscope.csv", "Another90/Magnetometer.csv");
    //DataLoader data = DataLoader("Slow90/Accelerometer.csv", "Slow90/Gyroscope.csv", "Slow90/Magnetometer.csv");


    SimulatedMagnetometer mag(data);
    mag.calibrate(magCalibrationData);
    magCalibrationData.clear();
    magCalibrationDataRaw.clear();

    SimulatedAccelerometer accel(data);

    SimulatedGyroscope gyro(data);
    gyro.calibrate(gyroCalibrationData);
    gyroCalibrationData.clear();
    gyroCalibrationDataRaw.clear();

    auto start = std::chrono::high_resolution_clock::now();
    double lastNew = 0;
    Vector3 lastRot = {0, 0, 0};
    Vector3 rot;
    bool ij = false;

    std::cout << std::endl;
    while(true){
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = now - start;

        if(time.count() > mag.allReadings.back().first){
            break;
        }

        mag.update(time.count());
        accel.update(time.count());
        gyro.update(time.count());

        bool isNew = false;
        Vector3 gyroV = gyro.getValue(isNew);
        if(isNew){

            rot += (gyroV + lastRot) / 2 * (time.count() - lastNew);
            if(ij){
                //std::cout << time.count() << ", ";
                //rot.print();
            }

            ij = !ij;
            //gyroV.print();
            lastNew = time.count();
            lastRot = gyroV;

        }

    }
    std::cout << std::endl;

    rot.print();
    //std::cout << lastNew << std::endl;
    //(rot / lastNew).print();




    return 0;
}



