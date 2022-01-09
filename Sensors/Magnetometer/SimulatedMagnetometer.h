//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_SIMULATEDMAGNETOMETER_H
#define IMUTRACKING2_SIMULATEDMAGNETOMETER_H

#include "Magnetometer.h"

#include <vector>
#include <utility>
#include <chrono>

#include "../../MathStuff/Vector3.h"
#include "../../DataLoading/DataLoader.h"

class SimulatedMagnetometer : public Magnetometer {
private:
    int currentMostRecentReading = -1;

public:
    std::vector<std::pair<double, Vector3>> allReadings;

    SimulatedMagnetometer(std::vector<double> times, std::vector<Vector3> readings);
    SimulatedMagnetometer(const DataLoader& data);

    void update(double time);
    bool isOutOfNewData() const;
};


#endif //IMUTRACKING2_SIMULATEDMAGNETOMETER_H
