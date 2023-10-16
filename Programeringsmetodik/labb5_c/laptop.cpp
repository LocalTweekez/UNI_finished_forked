#include "laptop.h"
#include <string>
#include <iostream>

laptop::laptop() {
    name = "";
    storageCapacity = 0;
    memory = 0;
}

laptop::laptop(std::string name, double storageCapacity, int memory, float price) :
        name(name), storageCapacity(storageCapacity), memory(memory), price(price)  {}

laptop::laptop(const laptop& rhs) {
    name = rhs.name;
    storageCapacity = rhs.storageCapacity;
    memory = rhs.memory;
    price = rhs.price;
}

laptop::~laptop() {
}

void laptop::setName(std::string Lname) {
    this->name = Lname;
}
void laptop::setStorage(double Lstorage) {
    this->storageCapacity = Lstorage;
}

void laptop::setMemory(int Lmemory) {
    this->memory = Lmemory;
}

void laptop::setPrice(float price){
    this->price = price;
}

float laptop::getPrice() const
{
    return this->price;
}

std::string laptop::getName() const  {
    return name;
}
double laptop::getStorage()  const {
    return storageCapacity;
}
int laptop::getMemory() const {
    return memory;
}

bool operator==(const laptop& left, const laptop& right) {
    if (left.name == right.name) {
        return true;
    }
    return false;
}


