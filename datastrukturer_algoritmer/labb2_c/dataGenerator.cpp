#include "dataGenerator.h"
#include <random>

void dataGenerator::generateConstant(std::vector<int> &data, int value, int size){
    data.clear();
    data.resize(size, value);
}

void dataGenerator::generateAscending(std::vector<int> &data, int size){
    data.clear();
    data.resize(size);
    for (int i = 0; i < size; i++){
        data[i] = i+1;
    }

}

void dataGenerator::generateDescending(std::vector<int> &data, int size){
    data.clear();
    data.resize(size);
    for (int i = size; i > 0; i--) {
        data[size-i] = i;
    }
}

void dataGenerator::generateRandom(std::vector<int> &data, int size){
    data.clear();
    data.resize(size);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, size);

    for (int i = 0; i < size; i++) {
        data[i] = distribution(generator);
    }
}
