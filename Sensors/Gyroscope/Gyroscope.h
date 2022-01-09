//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_GYROSCOPE_H
#define IMUTRACKING2_GYROSCOPE_H

#include <deque>
#include <utility>

#include "../../MathStuff/Vector3.h"

class Gyroscope {
protected:
    std::deque<std::pair<double, Vector3>> history;//Stores a history of every new reading over a set period of time
    std::deque<std::pair<double, Vector3>> calibratedHistory;//Stores a history of every new reading over a set period of time

    bool isNewReading = false;

    Vector3 applyCalibration(const Vector3& data);//happens before it is added to history
    Vector3 offset = {0, 0, 0};
    Vector3 standardDeviation = {0, 0, 0};
    Vector3 scaling = {1, 1, 1};
    //Vector3 scaling = {1, 1, 1.01574879736};
    //Vector3 scaling = {1, 1,  0.905863457036};

public:

    Vector3 getValue(bool& isNew);//gives the current sensor reading. The parameter is set to whether or not the given value is a new reading
    Vector3 getValue();//gives the current sensor reading.

    void calibrate(std::vector<Vector3> data);
    void setScaling(const Vector3& scaling);
    Vector3 getOffset() const;
};


#endif //IMUTRACKING2_GYROSCOPE_H



