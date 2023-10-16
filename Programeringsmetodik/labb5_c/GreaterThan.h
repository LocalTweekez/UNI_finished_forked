#ifndef GREATERTHAN_H
#define GREATERTHAN_H

#include "laptop.h"

class GreaterThan {
private:
    double value;

public:
    GreaterThan(int val) : value(val) {}
    bool operator()(const laptop& obj);
};


#endif //GREATERTHAN_H
