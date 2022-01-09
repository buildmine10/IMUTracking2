//
// Created by colli on 1/8/2022.
//

#ifndef IMUTRACKING2_MAGNETOMETER_H
#define IMUTRACKING2_MAGNETOMETER_H

#include <deque>
#include <utility>

#include "../../MathStuff/Vector3.h"

class Magnetometer {
protected:
    std::deque<std::pair<double, Vector3>> history;//Stores a history of every new reading over a set period of time
    bool isNewReading = false;

    //These would be applied to incoming readings
    Vector3 offset = {0, 0, 0};
    Vector3 scale = {1, 1, 1};
    Vector3 applyCalibration(const Vector3& data);

public:

    Vector3 getValue(bool& isNew);//gives the current sensor reading. The parameter is set to whether or not the given value is a new reading
    Vector3 getValue();//gives the current sensor reading.

    void calibrate(std::vector<Vector3> data);
    void calibrateUsingHistory();
    Vector3 getOffset() const;
    Vector3 getScale() const;
};


#endif //IMUTRACKING2_MAGNETOMETER_H
