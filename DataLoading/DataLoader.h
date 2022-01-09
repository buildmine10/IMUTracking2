//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_DATALOADER_H
#define IMUTRACKING2_DATALOADER_H
#include <map>
#include <string>
#include <array>

#include "../MathStuff/Vector3.h"

class DataLoader {
private:
    std::map<double, Vector3> accelData;
    std::map<double, Vector3> gyroData;
    std::map<double, Vector3> magData;
    double _startTime = 0, _endTime = 0;

    static void loadFromFile(std::string fileName, std::map<double, Vector3>& output);

public:

    const double& startTime{_startTime};
    const double& endTime{_endTime};

    DataLoader(std::string accelFile, std::string gyroFile, std::string magFile);
    void print();

    std::array<Vector3, 3> getClosestDataPoint(double time) const;
    const std::map<double, Vector3>& getAccelData() const;
    const std::map<double, Vector3>& getGyroData() const;
    const std::map<double, Vector3>& getMagData() const;
};
#endif //IMUTRACKING2_DATALOADER_H
