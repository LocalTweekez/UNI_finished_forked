//
// Created by tahak on 8/17/2023.
//

#include "roundedRect.h"

roundedRect::roundedRect(float _width, float _height, std::string _color): rectangle(_width, _height, _color){
}

float roundedRect::getArea() {
    return rectangle::getArea();
}




