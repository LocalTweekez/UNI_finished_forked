#include "mbed.h"
InterruptIn center(p14);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

void pressed(){
    led2 = !led2;
    }
void released(){
    led2 = !led2;
    led3 = !led3;
    wait(0.5);
    led3 = !led3;
    }

int main()
{
    center.rise(&pressed);
    center.fall(&released);
    
    while (1) {
     led1 = !led1;
     wait(0.5);

    }
}