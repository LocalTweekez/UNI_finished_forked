//
// Created by tahak on 8/17/2023.
//
#pragma once
#include "shape.h"
class rectangle : public shape{
protected:
    float width;
    float height;

public:

    explicit rectangle(float _width, float _height, std::string _color);

    float getHeight();
    float getWidth();
    float getArea();
};

