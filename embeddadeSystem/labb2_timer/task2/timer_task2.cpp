#include "mbed.h"
#include <string>
Serial pc(USBTX, USBRX); // tx, rx
Timer t;
int main() {
    
    char arr[40]; //40 characters size
    printf("write a string: "); 
    while(1) { 
        
        if(pc.readable()) { //if an input is detected
        
        scanf("%s", arr); //scan the input as a type string and put into array
        t.start(); //starting the timer
        for(int i = 0; i < strlen(arr); i++)
            printf("%c", arr[i]); //printing every char one at a time
        t.stop(); //stop the timer

        // print the time and the average by dividing with the size
        printf("The time taken was %f seconds\n", t.read());
        printf("Average time per character: %f seconds", t.read()/strlen(arr));
        
            
        }
    }
}