//
// Created by tahak on 8/17/2023.
//

#include "parallelepiped.h"

parallelepiped::parallelepiped(float _width, float _height, float _length, std::string _color) :
        rectangle(_width, _height,_color),
        length(_length){}

float parallelepiped::getLength(){
    return length;
}

float parallelepiped::getArea() {
    return rectangle::getArea();
}
