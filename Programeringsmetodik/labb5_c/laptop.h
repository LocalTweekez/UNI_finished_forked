#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include <iostream>

class laptop {

private:
    std::string name;
    double storageCapacity;
    int memory;
    double price;

public:
    laptop();
    laptop(std::string name, double storageCapacity, int memory, float price);
    laptop(const laptop& rhs);
    ~laptop();

    void setName(std::string Lname);
    void setStorage(double Lstorage);
    void setMemory(int Lmemory);
    void setPrice(float price);

    float getPrice() const;
    std::string getName() const;
    double getStorage() const;
    int getMemory() const;

    friend bool operator==(const laptop& left, const laptop& right);
};



#endif