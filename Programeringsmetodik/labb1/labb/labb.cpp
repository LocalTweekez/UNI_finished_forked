#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"


 void f(int_buffer buf) {

    
    for (auto e : buf) {
        std::cout << e << std::endl;
    }
    
};

int main()
{
    
    int_buffer buf(20);
    for (size_t i = 0; i < buf.size(); i++) {
        buf[i] = rand() % 100;
    }

    f(int_buffer(buf));
    int_sorted Sorted(buf.get_ptr(), buf.size());

    
    Sorted.print();
    Sorted.checkIfSorted();
    Sorted = Sorted.sort(Sorted.begin(), Sorted.end());
    Sorted.print();
    Sorted.checkIfSorted();
    


    return 0;
    
}

