//
// Created by Collin on 1/8/2022.
//

#ifndef IMUTRACKING2_CSVLOADER_H
#define IMUTRACKING2_CSVLOADER_H

#include <vector>
#include <string>

class CSVLoader {
private:

public:
    CSVLoader() = delete;

    static std::vector<std::vector<double>> loadFile(std::string fileName);//output dimensions are [y][x]
};



#endif //IMUTRACKING2_CSVLOADER_H
