//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_ACCELEROMETER_H
#define IMUTRACKING2_ACCELEROMETER_H

#include <deque>
#include <utility>

#include "../../MathStuff/Vector3.h"

class Accelerometer {
protected:
    std::deque<std::pair<double, Vector3>> history;//Stores a history of every new reading over a set period of time
    bool isNewReading = false;

    Vector3 applyCalibration(const Vector3& data);

public:
    Vector3 getValue(bool& isNew);//gives the current sensor reading. The parameter is set to whether or not the given value is a new reading
    Vector3 getValue();//gives the current sensor reading.

    //I'm really not sure how to calibrate an accelerometer
    void calibrate(std::vector<Vector3> data) = delete;
    void calibrateUsingHistory() = delete;

};


#endif //IMUTRACKING2_ACCELEROMETER_H
