#include "rectangle.h"

rectangle::rectangle(float _width, float _height, std::string _color):
        shape(_color),
        width(_width),
        height(_height)
        {}



float rectangle::getHeight()
{
    return height;
}

float rectangle::getWidth()
{
    return width;
}

float rectangle::getArea(){
    return width*height;
}











