//
// Created by tahak on 8/17/2023.
//
#pragma once
#include <string>
#include <iostream>
class shape{
    std::string color;

public:
    shape();
    explicit shape(std::string _color);

    std::string getColor() const;
    virtual float getArea() = 0;

};


