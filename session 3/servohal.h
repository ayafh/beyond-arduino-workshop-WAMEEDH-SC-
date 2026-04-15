
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

void servo_write(int angle) ; 
void Delay(unsigned int n ) ; 
void HW_init() ; 
void start_tiemr() ; 
void enableint() ; 
int map(long x, long in_min, long in_max, long out_min, long out_max);