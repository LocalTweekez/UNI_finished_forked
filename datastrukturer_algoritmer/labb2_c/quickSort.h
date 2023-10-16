//
// Created by tahak on 5/29/2023.
//

#ifndef LABB2_FINAL_QUICKSORT_H
#define LABB2_FINAL_QUICKSORT_H


#include <vector>

int medianOfThree(std::vector<int>& data, int low, int high);
int partition(std::vector<int>& data, int low, int high, bool useMedianOfThree = false);
void quicksort(std::vector<int>& data, int low, int high, bool useMedianOfThree = false);


#endif //LABB2_FINAL_QUICKSORT_H
