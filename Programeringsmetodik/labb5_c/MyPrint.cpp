#include "MyPrint.h"



void MyPrint::operator()(std::vector<laptop>& obj) const {
    for (int i = 0; i < obj.size(); i++) {
        std::cout << i+1 <<". " << obj[i].getName() << " |  " << obj[i].getStorage() << " GB Storage |  " << obj[i].getMemory() << "GB Memory | " << obj[i].getPrice() << " $;\n" << std::endl;
    }
}