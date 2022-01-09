#include <iostream>
#include <chrono>
#include <cmath>
#include "Sensors/MagnetometerProcessor.h"

using namespace std::chrono_literals;

int main() {

    MagnetometerProcessor mag;
    /*
    mag.getUpdate({0, 0, 0});
    mag.getUpdate({1, 0, 0});
    mag.getUpdate({2, 0, 0});
    */
    auto start = std::chrono::high_resolution_clock::now();
    int count = 0;
    bool isPing = false;
    while(true){
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = now - start;

        if(std::fmod(time.count(), 0.1) < 0.01 && !isPing){

            mag.getUpdate({(double)count, 0, 0});
            count++;
            isPing = true;
        }
        if(std::fmod(time.count(), 0.1) > 0.01){
            isPing = false;
        }

        if(time > 1s){
            break;
        }
    }

    std::chrono::duration<double> time = mag.historyDeltaTimes.front() - mag.historyDeltaTimes.back();

    mag.printData();
    return 0;
}
