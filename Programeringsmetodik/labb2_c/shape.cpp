//
// Created by tahak on 8/17/2023.
//

#include "shape.h"
#include <cmath>


shape::shape(){
    color = "colorless";
}
shape::shape(std::string _color){
    color = _color;
};

std::string shape::getColor() const{
    return color;
}




