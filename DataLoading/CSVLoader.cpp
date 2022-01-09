//
// Created by Collin on 1/8/2022.
//

#include "CSVLoader.h"
#include <fstream>
#include <iostream>

std::vector<std::vector<double>> CSVLoader::loadFile(std::string fileName) {
    std::ifstream file(fileName);

    std::vector<std::vector<double>> tempOutput;

    for (std::string line; std::getline(file, line); ){
        std::vector<std::string> data;
        int pos = 0;

        while(pos != std::string::npos){
            data.push_back(line.substr(pos,line.find(',', pos + 1) - pos));
            pos = line.find(',', pos + 1);
            if(data.back().at(0) == ','){
                data.back().erase(0, 1);
            }
        }

        tempOutput.emplace_back();
        for(auto d : data){
            try{
                tempOutput.back().push_back(std::stod(d));
            }catch(std::exception e){
                tempOutput.pop_back();
                break;
            }
        }
    }

    return tempOutput;
}
