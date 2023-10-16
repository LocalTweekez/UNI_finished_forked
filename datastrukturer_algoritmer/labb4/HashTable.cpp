//
// Created by tahak on 5/30/2023.
//

#include "HashTable.h"
#include <iostream>
#include <string>

bool HashTable::isEmpty() const {
    int sum{};
    for (int i = 0; i < hashGroups; ++i) {
        sum += table[i].size();
    }

    if (!sum){
        return true;
    }
    return false;
}

int HashTable::hashFunc(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value) {
    int hashValue = hashFunc(key);
    auto& cell = table[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (;itr !=end(cell) ; itr++) {
        if (itr->first == key){
            keyExists = true;
            itr->second = value;
            std::cout <<"[WARNING] Key exists. Value replaced"<< std::endl;
            break;
        }
    }
    if (!keyExists){
        cell.emplace_back(key,value);
    }
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunc(key);
    auto& cell = table[hashValue];
    auto itr = begin(cell);
    bool keyExists = false;
    for (;itr !=end(cell) ; itr++) {
        if (itr->first == key){
            keyExists = true;
            itr = cell.erase(itr);
            std::cout <<"[INFO] Item removed successfully"<< std::endl;
            break;
        }
    }
    if (!keyExists){
        std::cout<< "[ERROR] Key not found. No pair removed" << std::endl;
    }

}

std::string HashTable::searchTable(int key) {


    return nullptr;
}

void HashTable::printTable() {
    for (int i{}; i<hashGroups; i++){
        if (table[i].size() == 0) continue;
        auto itr = table[i].begin();
        for (; itr != table[i].end(); itr++) {
            std::cout<<"[Pairs] Key: " << itr->first << " Value: "<< itr->second << std::endl;
        }
    }

}
