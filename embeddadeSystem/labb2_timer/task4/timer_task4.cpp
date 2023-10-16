#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

Ticker ticker1;
Ticker ticker2;
Ticker ticker3;
Ticker ticker4;


void led1_tick(){
    led1 = !led1;
}

void led2_tick(){
    led2 = !led2;        
}

void led3_tick(){
    led3 = !led3;
}

void led4_tick(){    
    led4 = !led4;
}
    
int main(){
    ticker1.attach(led1_tick, 0.7);
    ticker2.attach(led2_tick, 1.2);
    ticker3.attach(led3_tick, 2.3);
    ticker4.attach(led4_tick, 3.9);
    
        
    while (1){
        
    }
}