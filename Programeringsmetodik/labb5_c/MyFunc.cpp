//
// Created by tahak on 8/17/2023.
//

#include "MyFunc.h"

MyFunc::MyFunc(double mean):
mean(mean) {

}

double MyFunc::operator()(double xi) {
    return xi - mean;
}
