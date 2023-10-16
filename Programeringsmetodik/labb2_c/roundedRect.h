//
// Created by tahak on 8/17/2023.
//

#pragma once
#include "rectangle.h"
class roundedRect :
        public rectangle{

public:
    roundedRect(float _width, float _height, std::string _color);
    float getArea();


};



