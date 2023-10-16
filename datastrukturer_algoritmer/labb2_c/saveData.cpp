#include "saveData.h"
#include <fstream>
#include<numeric>
#include <iostream>
#include <valarray>


double calculateStdDev(std::vector<float>& sortingTimes, float averageTime) {
    double sum = 0, stdDev = 0;

    for(int i = 0; i < sortingTimes.size(); i++) {
        sum += sortingTimes[i];
    }

    for(int i = 0; i < sortingTimes.size(); i++) {
        stdDev += pow(sortingTimes[i] - averageTime, 2);
    }

    return sqrt(stdDev / (sortingTimes.size() - 1));
}

void saveData(int elementcount, std::vector<float>& sortingTimes){
    std::ofstream output;
    output.open ("data.txt", std::ios::app);

    double averageTime = std::accumulate(sortingTimes.begin(), sortingTimes.end(), 0) / sortingTimes.size();
    double standardDeviation = calculateStdDev(sortingTimes, averageTime);

    output << elementcount << "|" << averageTime << "|" << standardDeviation << std::endl;
    std::cout << elementcount << "\t\t" << averageTime << "ms\t\t" << "\t" << standardDeviation << "\n";
    output.close();
}


void saveMethod(std::string sortingMethod, std::string dataOrder){
    std::ofstream output;
    output.open ("data.txt", std::ios::app);

    output << "Method:" << sortingMethod << std::endl;
    output << "order:" << dataOrder << std::endl;

    output.close();
}

