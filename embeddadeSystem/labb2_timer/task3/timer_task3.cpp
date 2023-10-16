#include "mbed.h"
#include <iostream>
DigitalOut center(p14);

Timeout timeout;

void timer(){
    std::cout <<"time ended " << std::endl;
}

  
int main(){
        
    while (1){
        int random = rand() % 6 + 5;
        if(center == 1){
            timeout.attach(&timer,random);
            for(int i = random; i > 0; i--){
                std::cout <<"Time Remaining: " << i << std::endl;
                wait(1);
            }
        }
    }
}