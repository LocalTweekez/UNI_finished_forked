#include "mbed.h"
#include "C12832.h"
AnalogIn pot(p19);
C12832 LCD(p5,p7,p6,p8,p11);

int main(){
    
    while(1){
          LCD.locate(0,0);
          LCD.printf("%2f Volt;", pot.read());
          wait(2);
          
        }
    
    
}