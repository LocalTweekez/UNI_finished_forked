//
// Created by tahak on 8/29/2023.
//

#ifndef LABB3_REPORTDATA_H
#define LABB3_REPORTDATA_H

#include "searching.h"

// Typedef for a quick table container
typedef std::pair<
        std::pair<
                std::vector<int>,       // Stores number of elements
                std::vector<int>>,    // Stores average time
        std::pair<
                std::vector<int>,       // Stores amount of samples
                std::vector<int>>     // Stores standard deviation
> container_table;


void saveData(const container_table &tableOfContents, const std::string& filepath, const std::string &method, int interval);
float calculateStdDev(std::vector<double>& data);


#endif //LABB3_REPORTDATA_H
