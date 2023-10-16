//
// Created by tahak on 8/17/2023.
//

#pragma once
#include "rectangle.h"
class parallelepiped :
        public rectangle{

private:
    float length;
public:

    parallelepiped(float _width, float _height, float _length, std::string _color);
    float getLength();
    float getArea();



};

