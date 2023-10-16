//
// Created by tahak on 8/17/2023.
//

#ifndef LABB5_C_MYBINOP_H
#define LABB5_C_MYBINOP_H
#include "laptop.h"
#include <numeric>


class MyBinOp {
public:
    double operator()(int value, const laptop &laptop);
};

#endif //LABB5_C_MYBINOP_H
