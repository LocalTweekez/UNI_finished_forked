/*
In this project we will create a TEMPRATURE monitor that writes out the values
on the LCD SCREEN and displays diffrent colors depending on the temprature, when
the temp is above 25 degrees we will display the rgb light red and when the temp
is below 10 degrees it will display blue, all other values between these two will be
green. A prompt is displayed on the lcd screen that tells the user to press the center joystick button
to save the values to a FILE on the board, this will allow users to save the data to use in future research or something else.
This projects uses all the Laborations that i did in the course and is perfect example of how we can use such a board.
Microcontrollers are not really known about but exists in every thing that connects to the electricity and has some kind of use
which means that we have them in almost everything nowadays. This was a very fun course but i would love to do something more
complicated in this subject where we could maybe program som kind of device that we use in daily baisis.

Taha Khudher.

*/
#include "mbed.h"
#include "LM75B.h" 
#include "C12832.h"
#include <fstream>
#include <stdio.h>
#include <iostream>

//inputs/outputs
C12832 LCD(p5, p7, p6, p8, p11);  //create the lcd screen object and with the right pins
LM75B thermometer(p28,p27); //define the sensor used to get the temprature values
I2C sensor(p28,p27);
DigitalIn center(p14); //define all the digital inputs and outputs used for the project
DigitalOut red(p23); 
DigitalOut green(p24);
DigitalOut blue(p25);


//files
LocalFileSystem local("local"); 
char* file = "/local/tempFile.txt";
char lastLine[256];

//global variables

float temprature;
FILE* fp; //filepointer
const int addr = 0x90;
float values[5]; // an array where all the values will be stored 

//function declaration
void getTemp();
void storeTemp();

// the main program loop where the program will be.
// the programs keeps running with a small delay until an interupt is there
// the delay is because the temprature doesnt really change so rapidly but instead gradually over time.
// the less resources we use the better.
int main(){
    while (1) {
        getTemp();
        if(center == 1){
            storeTemp();
        }
        wait_us(60000);
    }
}
//function implementations 
void getTemp(){    
    temprature = thermometer.temp();
    LCD.cls(); // clearing the lcd screen so we can print out the new information
    
    LCD.locate(1,1); //locating the top left corner to start writing
    LCD.printf("%f Celsius\n", temprature); //printing out the temprature we captured on the screen
    LCD.printf("Hold down the joystick to store temp"); // instructions for the user to save the values to a file.
    std::cout<<temprature;
    
    //if the temprature drops below 10 the light will turn blue to indicate cold, red for over 25 degrees and green between these two values.
    if (temprature < 10){
            green = red = 1; // Maximum of the dim, which turns off the rgb
            blue = 0.5; // Duty cycle to 50%, the signal is on 50% of the time
            
        }
    else if (temprature > 25){
            blue = green = 1;
            red = 0.5;
            
    }
    else{
           blue = red = 1; 
           green = 0.5;
    }
}
//storing the temprature to the filesystem on the mbed board.
//we appened to the file so that the old values dont get erased.
//then we close the file to ensure that nothing goes wrong. and the file pointer becomes a hanging pointer.
void storeTemp(){
    fp = fopen(file, "a"); //append
    fprintf(fp, "the temprature is %f degrees celsuis", temprature); 
    fprintf(fp,"\n");
    fclose(fp);
    
    }