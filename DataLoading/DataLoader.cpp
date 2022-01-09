//
// Created by colli on 1/8/2022.
//


#include "DataLoader.h"
#include <fstream>
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>

DataLoader::DataLoader(std::string accelFile, std::string gyroFile, std::string magFile) {
    DataLoader::loadFromFile(accelFile, accelData);
    DataLoader::loadFromFile(gyroFile, gyroData);
    DataLoader::loadFromFile(magFile, magData);
    _startTime = std::min(std::min(accelData.begin()->first, gyroData.begin()->first), magData.begin()->first);
    _endTime = std::min(std::min(accelData.rbegin()->first, gyroData.rbegin()->first), magData.rbegin()->first);
}

void DataLoader::loadFromFile(std::string fileName, std::map<double, Vector3> &output) {
    std::ifstream file{fileName};

    for (std::string line; std::getline(file, line); )
    {
        std::vector<std::string> data;
        int pos = 0;

        while(pos != std::string::npos){
            data.push_back(line.substr(pos,line.find(',', pos + 1) - pos));
            pos = line.find(',', pos + 1);
            if(data.back().at(0) == ','){
                data.back().erase(0, 1);
            }
        }

        try{
            double time = std::stod(data.at(0));
            double x = std::stod(data.at(1));
            double y = std::stod(data.at(2));
            double z = std::stod(data.at(3));

            output.emplace(time, Vector3(x, y, z));
        }catch(std::exception e){

        }

    }
}

void DataLoader::print() {
    std::cout << "Accel data" << std::endl;
    for(auto temp : accelData){
        std::cout << temp.first << ", " << temp.second.x << ", " << temp.second.y << ", " << temp.second.z << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Gyro data" << std::endl;
    for(auto temp : gyroData){
        std::cout << temp.first << ", " << temp.second.x << ", " << temp.second.y << ", " << temp.second.z << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Mag data" << std::endl;
    for(auto temp : magData){
        std::cout << temp.first << ", " << temp.second.x << ", " << temp.second.y << ", " << temp.second.z << std::endl;
    }
}

std::array<Vector3, 3> DataLoader::getClosestDataPoint(double time) const{
    return {accelData.lower_bound(time)->second, gyroData.lower_bound(time)->second, magData.lower_bound(time)->second};
}

const std::map<double, Vector3> &DataLoader::getAccelData() const {
    return accelData;
}

const std::map<double, Vector3> &DataLoader::getGyroData() const {
    return gyroData;
}

const std::map<double, Vector3> &DataLoader::getMagData() const {
    return magData;
}


