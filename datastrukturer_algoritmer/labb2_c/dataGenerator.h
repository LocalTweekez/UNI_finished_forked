//
// Created by tahak on 5/29/2023.
//

#ifndef LABB2_FINAL_DATAGENERATOR_H
#define LABB2_FINAL_DATAGENERATOR_H

#include "vector"

class dataGenerator{
public:

    static void generateConstant(std::vector<int>& data, int value, int size);
    static void generateAscending(std::vector<int>& data, int size);
    static void generateDescending(std::vector<int>& data, int size);
    static void generateRandom(std::vector<int>& data, int size);

};



#endif //LABB2_FINAL_DATAGENERATOR_H
