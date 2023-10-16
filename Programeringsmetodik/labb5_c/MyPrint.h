#ifndef MYPRINT_H
#define MYPRINT_H

#include <vector>
#include "laptop.h"

class MyPrint {
public:

    void operator()(std::vector<laptop>& obj) const;
};


#endif //LABB5_MYPRINT_H