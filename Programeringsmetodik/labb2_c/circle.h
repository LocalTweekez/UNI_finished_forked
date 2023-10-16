//
// Created by tahak on 8/17/2023.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "shape.h"

class circle :public shape{

protected:
    float radius;

public:
    explicit circle(float _radius, std::string color);
    float getRadius()const;
    float getArea();

};

#endif