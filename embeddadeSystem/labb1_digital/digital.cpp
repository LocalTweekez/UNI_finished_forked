#include "mbed.h"

DigitalIn up(p15);
DigitalIn down(p12);
DigitalIn left(p13);
DigitalIn right(p16);
DigitalIn center(p14);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


int main()
{
    while (true) {
        // if one of the pins assigned to the joystick gets activated 
        // one led will be turned on, each led is asigned to one pin
        // the center pin resets all leds
        if(up == 1)
            led1 = 1;

        if(down == 1)
            led2 = 1;
        
        if(left == 1)
            led3 = 1;
            
        if(right == 1)
            led4 = 1;
        
        if(center == 1){
            led1 = 0;
            led2 = 0;
            led3 = 0;
            led4 = 0;            
            }
     

    }
}