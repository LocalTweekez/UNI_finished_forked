//
// Created by tahak on 5/29/2023.
//

#ifndef LABB2_FINAL_SAVEDATA_H
#define LABB2_FINAL_SAVEDATA_H
#include <vector>
#include <string>

void saveData(int elementcount, std::vector<float>& sortingTimes);
void saveMethod(std::string sortingMethod, std::string dataOrder);
double calculateStdDev(std::vector<float>& sortingTimes, float averageTime);

#endif //LABB2_FINAL_SAVEDATA_H
