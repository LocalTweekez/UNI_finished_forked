#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#include "laptop.h"
#include "MyPrint.h"
#include "GreaterThan.h"
#include "MyBinOp.h"
#include "MyUnOp.h"
#include "MyFunc.h"


int main() {
    const size_t N = 6;
    std::array<laptop, N> laptopArray;
    std::vector<laptop> laptopVector;

    laptopArray[0].setName("Lenovo Legion 5 pro");
    laptopArray[1].setName("Dell XPS 14");
    laptopArray[2].setName("M1 MacBook Pro");
    laptopArray[3].setName("Asus vivobook");
    laptopArray[4].setName("Lenovo Legion 5 pro");
    laptopArray[5].setName("Hp probook 650 g3");

    laptopArray[0].setMemory(16);
    laptopArray[1].setMemory(16);
    laptopArray[2].setMemory(32);
    laptopArray[3].setMemory(8);
    laptopArray[4].setMemory(32);
    laptopArray[5].setMemory(24);

    laptopArray[0].setStorage(1024.0);
    laptopArray[1].setStorage(512.0);
    laptopArray[2].setStorage(2048.0);
    laptopArray[3].setStorage(128.0);
    laptopArray[4].setStorage(2048.0);
    laptopArray[5].setStorage(256.0);


    laptopArray[0].setPrice(2099.99);
    laptopArray[1].setPrice(1499);
    laptopArray[2].setPrice(2799.99);
    laptopArray[3].setPrice(649);
    laptopArray[4].setPrice(2599.99);
    laptopArray[5].setPrice(399.39);


    for(size_t i = 0; i < N; i++) {

        laptop tempLaptop(laptopArray[i]);
        laptopVector.push_back(tempLaptop);
    }

    MyPrint print;
    print(laptopVector);


    // 1
    //Apply the generic algorithm for_each to print the vector contents.
    std::cout << "\n######################  ASSIGNMENT 1  ##########################" << std::endl;

    auto printer = [](const laptop& obj) {
        std::cout << obj.getName() << " |  " << obj.getStorage() << " GB Storage |  " << obj.getMemory() << "GB Memory | " << obj.getPrice() << " $;\n" << std::endl;
    };
    std::for_each(laptopVector.begin(), laptopVector.end(), printer);

    // 2
    //Buyers want a laptop with more than 8 GB ram
    std::cout << "\n######################  ASSIGNMENT 2  ##########################" << std::endl;
    auto moreThan8 = std::find_if(laptopVector.begin(), laptopVector.end(), GreaterThan(8));
    std::cout << moreThan8->getName() << " |  " << moreThan8->getStorage() << " GB Storage |  " << moreThan8->getMemory() << "GB Memory | " << moreThan8->getPrice() << " $;" << std::endl;

    //3
    //find same laptops with diffrent specs
    std::cout << "\n######################  ASSIGNMENT 3  ##########################" << std::endl;
    auto Adjacent = [](const laptop& laptop1, const laptop& laptop2) {
        return (laptop1 == laptop2);
    };


    auto iterator = std::adjacent_find(laptopVector.begin(), laptopVector.end(), Adjacent);
    if (iterator == laptopVector.end()) {
        std::cout << "no computers with diffrent specs" << std::endl;
    }
    else {
        std::cout<< "Found a computer with two variants"<< std::distance(laptopVector.begin(), iterator)<< std::endl;
    }


    //4
    std::cout << "\n######################  ASSIGNMENT 4  ##########################" << std::endl;
    auto isEqual = [](laptop& cont1Item, laptop& cont2Item) {
        return (cont1Item == cont2Item &&
                cont1Item.getMemory() == cont2Item.getMemory() &&
                cont1Item.getStorage() == cont2Item.getStorage()&&
                cont1Item.getPrice() == cont2Item.getPrice());
    };

    if (std::equal(laptopVector.begin(), laptopVector.end(), laptopArray.begin(), isEqual)) {
        std::cout << "The containers have equal elements. " << std::endl;
    }
    else {
        std::cout << "The containers does NOT have equal elements" << std::endl;

    }

    //5
    std::cout << "\n######################  ASSIGNMENT 5  ##########################" << std::endl;
    std::vector<laptop> subPart;
    subPart.push_back(laptopVector[3]);
    subPart.push_back(laptopVector[4]);

    auto haystack_itr = std::search(laptopVector.begin(), laptopVector.end(),subPart.begin(), subPart.end());

    if (haystack_itr != laptopVector.end()){
        std::cout<< "found at position " << std::distance(laptopVector.begin(), haystack_itr)<< std::endl;
    }
    else{
        std::cout<< "no match found" << std::endl;
    }
    std::cout << "\n######################  ASSIGNMENT 6  ##########################" << std::endl;
    MyBinOp mean;
    auto meanValue = std::accumulate(laptopVector.begin(), laptopVector.end(), double(),mean) / laptopVector.size();
    std::cout << "The mean value is " << meanValue<< std::endl;

    std::cout << "\n######################  ASSIGNMENT 7  ##########################" << std::endl;
    std::vector<double> v2;
    MyUnOp unOp;
    v2.resize(laptopVector.size());
    std::transform(laptopVector.begin(),laptopVector.end(), v2.begin(),unOp);

    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] <<std::endl;
    }
    std::cout << "\n######################  ASSIGNMENT 8  ##########################" << std::endl;
    MyFunc func(meanValue);
    std::transform(v2.begin(),v2.end(), v2.begin(), func);
    for (int i = 0; i < v2.size(); ++i) {
        std::cout<<v2[i]<< std::endl;
    }

    std::cout << "\n######################  ASSIGNMENT 9  ##########################" << std::endl;
    std::sort(v2.begin(),v2.end());
    for (int i = 0; i < v2.size(); ++i) {
        std::cout<<v2[i]<< std::endl;
    }

    return 0;
}