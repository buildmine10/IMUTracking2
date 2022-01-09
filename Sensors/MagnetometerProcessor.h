//
// Created by Collin on 1/7/2022.
//

#ifndef IMUTRACKING2_MAGNETOMETERPROCESSOR_H
#define IMUTRACKING2_MAGNETOMETERPROCESSOR_H

#include <deque>
#include <chrono>
#include <vector>

#include "../MathStuff/Vector3.h"

class MagnetometerProcessor {
public:
    std::deque<Vector3> history;
    std::deque<std::chrono::duration<double>> historyDeltaTimes;
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> pastTime;

public:
    void getUpdate(const Vector3& value);

    void printData() const;

    void calibrateMagnetometer(std::vector<Vector3> data);
};


#endif //IMUTRACKING2_MAGNETOMETERPROCESSOR_H
