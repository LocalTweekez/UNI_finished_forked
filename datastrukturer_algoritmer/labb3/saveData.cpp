//
// Created by tahak on 8/29/2023.
//

#include "saveData.h"

void saveData(const container_table &tableOfContents,
              const std::string& filepath,
              const std::string &method,
              int intervals) {
    std::ofstream output;
    output.open(filepath, std::ios_base::app);

    if(!output.is_open()) {
        std::cout << "Error opening file for writing!\n";
    }

    output << "M//" << method << "//" << intervals+1 << std::endl;
    if(tableOfContents.first.first.size() == tableOfContents.first.second.size()) {
        output << "#0#0#0#0" << std::endl;
        for(int i = 0; i < tableOfContents.first.first.size(); i++) {
            output << "#" << tableOfContents.first.first[i] << "#" << tableOfContents.first.second[i] << "#" << tableOfContents.second.first[i] << "#" << tableOfContents.second.second[i] << std::endl;
        }
    }

    output.close();

}


float calculateStdDev(std::vector<double>& data) {
    double sum = 0.0;
    double mean = 0.0;
    double variance = 0.0;
    double stddev = 0.0;

    // Calculate the sum of the elements
    for (double num : data) {
        sum += num;
    }

    // Calculate the mean
    mean = sum / data.size();

    // Calculate the squared differences from the mean
    for (double num : data) {
        variance += pow(num - mean, 2);
    }

    // Calculate the variance (by sample)
    variance /= (data.size() - 1);

    // Calculate the standard deviation (square root of the variance)
    stddev = sqrt(variance);

    return stddev;
}