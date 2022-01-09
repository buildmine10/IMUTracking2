//
// Created by colli on 1/8/2022.
//

#include "SimulatedMagnetometer.h"

#include <stdexcept>
#include <iostream>

void SimulatedMagnetometer::update(double time) {
    for(int i = currentMostRecentReading + 1; i < allReadings.size(); i++){
        if(allReadings.at(i).first <= time){//for any readings that should have happened by now
            auto dataPoint = allReadings.at(i);
            dataPoint.second = applyCalibration(dataPoint.second);
            history.push_front(dataPoint);
            isNewReading = true;//this section of the code only runs when there are new readings

            if(i == allReadings.size() - 1){//If the last bit of data is added to the history, it must be set as the most recent reading
                currentMostRecentReading = i;
            }
        }else{//when the readings being checked are now in the future
            currentMostRecentReading = i - 1;//Sets the most recent reading to the last reading that wasn't in the future
            break;
        }
    }

    while(history.size() > 1 && history.front().first - history.back().first > 1){//while history contains readings more than a second in the past relative to the most recent reading, remove those readings
        history.pop_back();
    }
}

SimulatedMagnetometer::SimulatedMagnetometer(std::vector<double> times, std::vector<Vector3> readings) {
    if(times.size() != readings.size()){
        throw std::runtime_error("When simulating a magnetometer every reading must have a time.");
    }

    for(int i = 0; i < times.size(); i++){
        allReadings.emplace_back(times.at(i), readings.at(i));
    }
}

bool SimulatedMagnetometer::isOutOfNewData() const{
    return currentMostRecentReading == allReadings.size() - 1;
}

SimulatedMagnetometer::SimulatedMagnetometer(const DataLoader &data) {
    allReadings.reserve(data.getAccelData().size());
    for(auto dataPoint : data.getMagData()){
        allReadings.emplace_back(dataPoint.first, dataPoint.second);
    }
}
