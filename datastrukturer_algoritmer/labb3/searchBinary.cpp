//
// Created by tahak on 8/29/2023.
//
#include "searchBinary.h"

/*
searchBinary::searchBinary(std::vector<int> &vec) {
    vecPrime = vec;
}

int searchBinary::Search(int searchNum, std::vector<int>& vec) {
    int mid = 0;
    int left = 0;
    int right = vec.size();

    while(left <= right) {
        mid = (left + right) / 2;

        if(vec[mid] == searchNum) {
            return mid;
        }
        else if(vec[mid] < searchNum) {
            left = mid + 1;
        }
        else if(vec[mid] > searchNum) {
            right = mid - 1;
        }
    }
    return -1;
}

void searchBinary::print() {
    for(auto &e : vecPrime) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
*/

int searchBinary(int searchNum, std::vector<int>& vec) {
    int mid = 0;
    int left = 0;
    int right = vec.size();

    while(left <= right) {
        mid = (left + right) / 2;

        if(vec[mid] == searchNum) {
            return mid;
        }
        else if(vec[mid] < searchNum) {
            left = mid + 1;
        }
        else if(vec[mid] > searchNum) {
            right = mid - 1;
        }
    }
    return -1;
}