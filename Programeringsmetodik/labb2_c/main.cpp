#include <iostream>
#include <vector>
#include "geometry.h"


void getData(std::vector<shape*> container) {
    float totalArea = 0;
    for (int i = 0; i < container.size(); i++) {
        totalArea += container[i]->getArea();
        std::cout << "Area: " << container[i]->getArea()<< std::endl;
        std::cout << "Color: " << container[i]->getColor() << std::endl;

        std::cout << std::endl;
    }
    std::cout << "Total Area: " << totalArea << std::endl;
}


int main(){
    std::vector <shape*> container;


    shape* rect = new rectangle(10, 15, "Red");
    shape* square = new rectangle(10, 10, "Blue");
    shape* cube = new parallelepiped(17, 17, 17, "green");
    shape* par = new parallelepiped(17, 18, 19, "White");
    shape* roundRect = new roundedRect(6, 7, "black");
    shape* cir = new circle(5, "purple");
    shape* cyl = new cylinder(5, 5, "yellow");

    container.push_back(rect);
    container.push_back(square);
    container.push_back(cube);
    container.push_back(par);
    container.push_back(roundRect);
    container.push_back(cir);
    container.push_back(cyl);



    getData(container);


}

