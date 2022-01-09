//
// Created by Collin on 1/7/2022.
//

#include "MagnetometerProcessor.h"
#include <iostream>
#include <iomanip>

void MagnetometerProcessor::getUpdate(const Vector3 &value) {
    auto now = std::chrono::high_resolution_clock::now();
    historyDeltaTimes.push_front(now - pastTime);
    history.push_front(value);
    pastTime = now;
}

void MagnetometerProcessor::printData() const {
    for(int i = history.size() - 2; i >= 0; i--){
        std::cout << historyDeltaTimes.at(i).count() << ": ";
        history.at(i).print();
    }
}
