#include"servohal.h"



int  main() {
    HW_init(); 
    enableint() ; 
    start_tiemr() ; 

    while(1) {
        for (uint8_t i=0 ; i<= 180 ; i+= 10){
        servo_write(i); 
        Delay(50);
    }

    for(uint8_t i=180 ; i>0 ; i-=10){
        servo_write(i); 
        Delay(50);
    }
    }
}