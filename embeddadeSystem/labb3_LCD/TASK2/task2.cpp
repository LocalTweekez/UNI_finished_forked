#include "mbed.h"
#include "C12832.h"
#include "treedude.h"


C12832 LCD(p5,p7,p6,p8,p11);
DigitalIn down(p12);
DigitalIn up(p15);
DigitalIn left(p13);
DigitalIn right(p16);

float x = 0;
float y = 0;


int main(){
    while(1){
        // Clear screen
        LCD.cls();

        // When the joystick is moved in a certain direction,
        //the caracter moves to that direction with a change of 0.2
        //the character moves until the pixel limits
        if(up==1) y-=0.5;
        if(down==1) y+=0.5;
        if(right==1) x+=0.5;
        if(left==1) x-=0.5;

        // If the bitmap figure is out of the LCD screen,
        // reposition the bitmap to the opposite side
        if(x > 112) x = 112;
        if(x < 0) x = 0;
        if(y > 16) y = 16;
        if(y < 0) y = 0;

        // Print the bitmap to LCD
        LCD.print_bm(bitmTreedude,x,y);
        LCD.copy_to_lcd();
        }
}