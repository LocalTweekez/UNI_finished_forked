//
// Created by tahak on 8/17/2023.
//

#pragma once
#include "circle.h"
class cylinder :
        public circle{
private:
    float height;

public:
    cylinder(float radius, float height, std::string color);
    float getHeight();
    float getArea();



};

