#include "int_buffer.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

int_buffer::int_buffer() {
    buffer = nullptr;
    length = 0;

};

int_buffer::int_buffer(size_t size) : 
    length(size),
    buffer(new int[size]){

    
}; // size_t is defined in cstdlib

int_buffer::int_buffer(const int* source, size_t size):int_buffer(size) {
    std::copy(source, source + size, buffer);
    

};

int_buffer::int_buffer(const int_buffer& rhs):
        int_buffer(rhs.begin(), rhs.size()){

    
    //std::copy(rhs.begin(), rhs.end(), buffer);
  
}; // copy construct

int_buffer::int_buffer(int_buffer&& rhs)noexcept{

    *this = std::move(rhs);


}; // move construct

int_buffer& int_buffer::operator=(const int_buffer& rhs){

    if (this != &rhs) {
        delete[] buffer;
        length = rhs.length;
        buffer = new int[length];
        std::copy(rhs.begin(), rhs.end(), buffer);
    }
    return *this;
    

}; // copy assign

int_buffer& int_buffer::operator=(int_buffer && rhs){

    if (this != &rhs) {
        delete[] buffer;
        
        buffer = rhs.buffer;
        length = rhs.length;

        rhs.buffer = nullptr;
        rhs.length = 0;


    }
    return *this;
    
}; // move assign

int& int_buffer::operator[](size_t index) {
    int* i = begin() + index;

    return *i;
};

const int& int_buffer::operator[](size_t index) const {
    const int* i = begin() + index;

    return *i;
};

size_t int_buffer::size() const {
    return length;
};

int* int_buffer::begin() {
    
    return buffer;
};

int* int_buffer::end() {
    
    return  buffer + size();
};

const int* int_buffer::begin() const {

    return buffer;
};

const int* int_buffer::end() const {
    return buffer + size();
};

int_buffer::~int_buffer() {

    delete[] buffer;

};

void int_buffer::print(){

    for (const int* i = begin(); i != end(); i++)
    {
        std::cout << *i << std::endl;
    }

};

void int_buffer::addData() {
    int num =  1;
    for (int * i = begin(); i != end(); i++){
        *i = num++ ;
    }


};

int* int_buffer::get_ptr() {
    return buffer;
};
