//
// Created by tahak on 8/29/2023.
//


#include "searchLinear.h"

/*
searchLinear::searchLinear(std::vector<int> &vec) {
    vecPrime = vec;
}

int searchLinear::Search(int searchNum, std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == searchNum) {
            return i;
        }
    }
    return -1;
}


void searchLinear::print() {
    for(auto &e : vecPrime) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

*/

int searchLinear(int searchNum, std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == searchNum) {
            return i;
        }
    }
    return -1;
}