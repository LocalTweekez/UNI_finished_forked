//
// Created by tahak on 8/29/2023.
//

#ifndef LABB3_HASH_SEARCH_H
#define LABB3_HASH_SEARCH_H

#include "searching.h"
#include "searchLinear.h"

class Hash_Search {
private:
    int mapSize;
    std::vector<std::vector<int>>& hashMap;

public:
    Hash_Search(std::vector<int> &vec, std::vector<std::vector<int>>& hashTable);
    int getAddress(int key, int size);
    std::pair<int, int> hashSearch(int key);
    void printHashMap();
    void refillMap(std::vector<int> &primeVector, int hashMapSize, int elementSize, int index);
};


#endif //LABB3_HASH_SEARCH_H
