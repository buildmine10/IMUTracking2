//
// Created by colli on 1/8/2022.
//

#include "Accelerometer.h"

Vector3 Accelerometer::getValue(bool &isNew) {
    isNew = isNewReading;//if it is a new reading this will be true
    isNewReading = false;//the reading is no longer new

    if(!history.empty()){
        return history.front().second;//the first element of history should be the most recent reading
    }else{
        return {0, 0, 0};
    }
}

Vector3 Accelerometer::getValue() {
    isNewReading = false;//the reading is no longer new
    if(!history.empty()){
        return history.front().second;//the first element of history should be the most recent reading
    }else{
        return {0, 0, 0};
    }
}

Vector3 Accelerometer::applyCalibration(const Vector3 &data) {
    return data;
}
