#include "mbed.h"
#include "C12832.h"


// I2C connection
I2C i2c(p28, p27);
C12832 lcd(p5,p7,p6,p8,p11);

// Address of the I2C board
const int addr = 0x90;

// Graph properties
const int xMax = 128;
const int yMax = 30; 

// drawing the grid
void drawGrid(){
    // Each step of the x- and y- axis has a distance of
    // 12 and 6 to fit 10 points each
    int xStep = 12;
    int yStep = 6;

    // Clear the screen and draw the lines according to the
    // graph properties
    lcd.cls();
    lcd.line(0,yMax,xMax,yMax,1);
    lcd.line(0,0,0,yMax,1);

    // Draw a point for every step on the LCD screen
    // to display a complete coordinate system with 10 steps at each line
    for(int i=0;i<=10;i++){
        int currXStep = xStep*i;
        int currYStep = yStep*i-5;
        lcd.line(currXStep,yMax,currXStep,yMax-1,1);
        lcd.line(0,currYStep,1,currYStep,1);
        }
}

// Function to get the temperature and place the value
// in the coordinate system, with x being the period and y the temperature
float getTemp(){

    // Read the temperature using a two element char array
    // to store I2C adresses
    char cmd[2];
    int count=0;
    while (1) {
        cmd[0] = 0x01;
        cmd[1] = 0x00;
        i2c.write(addr, cmd, 2);

        // Time period is 10 seconds
        ThisThread::sleep_for(100);
        count++;

        // Reset the coordinate system and start the sequence over again
        // if the screen fills up, 10 points
        if(count>128){
            lcd.cls();
            drawGrid();
            count = 1; }

        // Set pointer register to "data register" and send
        // the data to "read temp" pointer and read the two byte temp data
        cmd[0] = 0x00;
        i2c.write(addr, cmd, 1);
        i2c.read(addr, cmd, 2);

        // The temperature on the coordinate system is scaled down
        // and a circle is plotted on the coordinate system
        float tmp = (float((cmd[0]<<8)|cmd[1]) / 256.0);
        lcd.pixel(count,(int)(31-(tmp*0.62)),1);
        lcd.copy_to_lcd();
   }
}


int main() {
    drawGrid();
    getTemp();
}