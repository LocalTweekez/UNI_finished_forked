//
// Created by tahak on 8/29/2023.
//

#include "Hash_Search.h"

Hash_Search::Hash_Search(std::vector<int> &vec, std::vector<std::vector<int>>& hashTable)
        : hashMap(hashTable) {
    int hash = 0;
    mapSize = hashMap.size();

    for(int i = 0; i < vec.size(); i++) {
        hash = getAddress(vec[i], mapSize);
        hashMap[hash].push_back(vec[i]);
    }
}

int Hash_Search::getAddress(int key, int size) {
    return key % size;
}

std::pair<int,int> Hash_Search::hashSearch(int key) {
    int hash = getAddress(key, mapSize);
    int depth = hashMap[hash].size();

    for(int i = 0; i < depth; i++) {
        if(hashMap[hash][i] == key) {
            return std::make_pair(hash, i);
        }
    }

    return std::make_pair(hash,-1);
}

void Hash_Search::printHashMap() {

    for(int i = 0; i < mapSize; i++) {
        for(int j = 0; j < hashMap[i].size(); j++) {
            std::cout << "Element: " << i << " value: " << hashMap[i][j] << "\n";
        }
    }
}

void Hash_Search::refillMap(std::vector<int> &primeVector, int hashMapSize, int elementSize, int index = 1) {
    for (int x = 0; x < mapSize; x++) {					//Clear the old hashmap, each vector
        for (int y = 0; y < hashMap[x].size(); y++) {
            hashMap[x].clear();
        }
    }
    hashMap.clear();
    hashMapSize = (elementSize * index);
    hashMap.resize(hashMapSize);

    for(int i = 0; i < elementSize * index; i++) {
        hashMap[getAddress(primeVector[i], hashMapSize)].push_back(primeVector[i]);
    }
}

