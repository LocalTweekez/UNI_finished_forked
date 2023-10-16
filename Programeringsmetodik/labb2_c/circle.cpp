//
// Created by tahak on 8/17/2023.
//

#include "circle.h"
#include <cmath>

circle::circle(float _radius, std::string color):
        shape(color),
        radius(_radius){
}

float circle::getRadius()const {
    return radius;
}

float circle::getArea() {
    return radius*radius * M_PI;
}


