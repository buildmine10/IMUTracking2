//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_SIMULATEDGYROSCOPE_H
#define IMUTRACKING2_SIMULATEDGYROSCOPE_H

#include "Gyroscope.h"
#include "../../DataLoading/DataLoader.h"

class SimulatedGyroscope : public Gyroscope {
private:
    int currentMostRecentReading = -1;

public:
    std::vector<std::pair<double, Vector3>> allReadings;

    SimulatedGyroscope(std::vector<double> times, std::vector<Vector3> readings);
    SimulatedGyroscope(const DataLoader& data);

    void update(double time);
    bool isOutOfNewData() const;
};


#endif //IMUTRACKING2_SIMULATEDGYROSCOPE_H
