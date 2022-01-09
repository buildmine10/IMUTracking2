//
// Created by colli on 1/8/2022.
//

#include "Gyroscope.h"
#include <iostream>
#include <cmath>
#include <iterator>

Vector3 Gyroscope::getValue(bool &isNew) {
    isNew = isNewReading;//if it is a new reading this will be true
    return getValue();
}

Vector3 Gyroscope::getValue() {
    isNewReading = false;//the reading is no longer new
    if(!history.empty()){
        return calibratedHistory.front().second;//the first element of history should be the most recent reading
    }else{
        return {0, 0, 0};
    }
}

Vector3 Gyroscope::applyCalibration(const Vector3& data) {
    Vector3 output = data;

    std::vector<double> toAvgX = {output.x};
    std::vector<double> toAvgY = {output.y};
    std::vector<double> toAvgZ = {output.z};
    bool stopX = false, stopY = false, stopZ = false;

    for(int i = 0; i < history.size(); i++){
        auto diff = output - calibratedHistory.at(i).second;

        if(!stopX && std::abs(diff.x) <  3 * standardDeviation.x){
            toAvgX.push_back(history.at(i).second.x);
        }else{
            stopX = true;
        }
        if(!stopY && std::abs(diff.y) < 3 * standardDeviation.y){
            toAvgY.push_back(history.at(i).second.y);
        }
        else{
            stopY = true;
        }
        if(!stopZ && std::abs(diff.z) < 3 * standardDeviation.z){
            toAvgZ.push_back(history.at(i).second.z);
        }else{
            stopZ = true;
        }
    }
    double x = 0;
    for(auto& d : toAvgX){
        x += d;
    }
    x /= toAvgX.size();

    double y = 0;
    for(auto& d : toAvgY){
        y += d;
    }
    y /= toAvgY.size();

    double z = 0;
    for(auto& d : toAvgZ){
        z += d;
    }
    z /= toAvgZ.size();

    output = {x, y, z};

    return (output - offset).multiplyElementWise(scaling);
}

void Gyroscope::calibrate(std::vector<Vector3> data) {
    Vector3 average;
    for(auto& d : data){
        average += d;
    }
    average /= data.size();
    offset = average;
    //average.print();

    standardDeviation = {0, 0, 0};
    for(auto& d : data){
        auto diff = d - average;
        standardDeviation += {diff.x * diff.x, diff.y * diff.y, diff.z * diff.z};
    }
    standardDeviation /= data.size();
    standardDeviation = {std::sqrt(standardDeviation.x), std::sqrt(standardDeviation.y), std::sqrt(standardDeviation.z)};
    //standardDeviation.print();

}

Vector3 Gyroscope::getOffset() const {
    return offset;
}

void Gyroscope::setScaling(const Vector3& scaling) {
    this->scaling = scaling;
}




