//
// Created by tahak on 8/17/2023.
//

#include "MyUnOp.h"
double MyUnOp::operator()(const laptop& laptop){
    return laptop.getPrice();
}