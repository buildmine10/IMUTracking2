//
// Created by colli on 1/8/2022.
//

#include "Magnetometer.h"

Vector3 Magnetometer::getValue(bool &isNew) {
    isNew = isNewReading;//if it is a new reading this will be true
    isNewReading = false;//the reading is no longer new

    if(!history.empty()){
        return history.front().second;//the first element of history should be the most recent reading
    }else{
        return {0, 0, 0};
    }
}

Vector3 Magnetometer::getValue() {
    isNewReading = false;//the reading is no longer new
    if(!history.empty()){
        return history.front().second;//the first element of history should be the most recent reading
    }else{
        return {0, 0, 0};
    }
}

void Magnetometer::calibrate(std::vector<Vector3> data) {
    Vector3 min = data.at(0);
    Vector3 max = data.at(0);

    for(auto dataPoint : data){
        if(dataPoint.x < min.x){
            min += {dataPoint.x - min.x, 0, 0};
        }
        if(dataPoint.x > max.x){
            max += {dataPoint.x - max.x, 0, 0};
        }

        if(dataPoint.y < min.y){
            min += {0, dataPoint.y - min.y, 0};
        }
        if(dataPoint.y > max.y){
            max += {0, dataPoint.y - max.y, 0};
        }

        if(dataPoint.z < min.z){
            min += {0, 0, dataPoint.z - min.z};
        }
        if(dataPoint.z > max.z){
            max += {0, 0, dataPoint.z - max.z};
        }
    }

    offset = (max + min) / 2;
    Vector3 avgDeltaV = (max - min) / 2;
    double avgDelta = (avgDeltaV.x + avgDeltaV.y + avgDeltaV.z) / 3;
    scale = {avgDelta / avgDeltaV.x, avgDelta / avgDeltaV.y, avgDelta / avgDeltaV.z};
}

void Magnetometer::calibrateUsingHistory() {
    std::vector<Vector3> data;
    data.reserve(history.size());
    for(auto n : history){
        data.push_back(n.second);
    }
    calibrate(data);
}

Vector3 Magnetometer::getOffset() const {
    return offset;
}

Vector3 Magnetometer::getScale() const {
    return scale;
}

Vector3 Magnetometer::applyCalibration(const Vector3 &data) {
    return (data- offset).multiplyElementWise(scale);
}


