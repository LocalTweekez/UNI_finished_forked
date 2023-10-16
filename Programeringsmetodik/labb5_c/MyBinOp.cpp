//
// Created by tahak on 8/17/2023.
//

#include "MyBinOp.h"

double MyBinOp::operator()(int value, const laptop &laptop) {
    return  value + laptop.getPrice();
}

