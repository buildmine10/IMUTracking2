//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_SIMULATEDACCELEROMETER_H
#define IMUTRACKING2_SIMULATEDACCELEROMETER_H

#include "Accelerometer.h"
#include "../../DataLoading/DataLoader.h"

class SimulatedAccelerometer : public Accelerometer {
private:
    int currentMostRecentReading = -1;

public:
    std::vector<std::pair<double, Vector3>> allReadings;

    SimulatedAccelerometer(std::vector<double> times, std::vector<Vector3> readings);
    SimulatedAccelerometer(const DataLoader& data);

    void update(double time);
    bool isOutOfNewData() const;
};


#endif //IMUTRACKING2_SIMULATEDACCELEROMETER_H
