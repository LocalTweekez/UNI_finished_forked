//
// Created by tahak on 5/30/2023.
//

#ifndef LABB4_HASHTABLE_H
#define LABB4_HASHTABLE_H


#include <string>

class HashTable{
    static const int hashGroups = 10;
    list<pair<int, std::string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunc(int key);
    void insertItem(int key, std::string value);
    void removeItem(int key);
    std::string searchTable(int key);
    void printTable();

};



#endif //LABB4_HASHTABLE_H
