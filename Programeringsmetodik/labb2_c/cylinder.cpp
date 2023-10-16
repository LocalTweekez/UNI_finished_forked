//
// Created by tahak on 8/17/2023.
//

#include "cylinder.h"

cylinder::cylinder(float radius, float _height, std::string color):
        circle(radius, color), height(_height){}


float cylinder::getHeight(){
    return height;
}
float cylinder::getArea() {
    return circle::getArea();
};





