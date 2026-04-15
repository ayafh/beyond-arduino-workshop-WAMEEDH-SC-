
#include"servohal.h"

#define PINMASK(x) (1U << x)
#define FCPU 16000000L

uint16_t PWM = 500; 
volatile uint8_t delay_count = 0 ; 

void HW_init(){
    // The Timer1 Output Compare Unit B (OC1B) is mapped to PB2 (pin 10) -- need to be set as OUTPUT 
    DDRB |= PINMASK(2);
    // SELECT THE MODE TO FAST PWM (15) AT OC1B ; BITS WGM13:12 ALL HIGH 
    TCCR1A |= (1 << COM1B1) | (1 << WGM11) | (1<<WGM10) ; 
    TCCR1B |= (1<<WGM12)| (1<< WGM13) ;
    // TOP VALUE OF THE TIMER (TO DEFINE THE FREQUENCY) 
    OCR1A = 4999 ;  
    //RESET THE COUNTER COUNTER TO 0  
    TCNT1 = 0 ; 
    // ENABLE THE OVERFLOW INTERRUPT 
    TIMSK1 |= (1<< OCIE1A);
    //ADJUST THE DUTY CYCLE 
    OCR1B = (PWM/1000000)* FCPU /64 -1 ; 
    
}

void servo_write(int angle){
    cli(); // disable global interrupts
    PWM = map(angle , 0, 180, 500, 2400); 
    sei(); // enable global interrupts 
}

ISR(TIMER1_COMPA_vect){
    // OCR1B= PULSE WIDTH IN SEC * TIMER FREQUENCY -1 
    OCR1B = (PWM/1000000.0)*FCPU /64-1 ; 
    delay_count++ ;
}

void Delay(unsigned int n ) {
    cli(); 
    delay_count = 0 ; 
    sei(); 
    while (delay_count <n) ;
}
int map(long x, long in_min, long in_max, long out_min, long out_max) {
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void start_tiemr() {
    // CONFIGURE THE PRESCALAR TO 64 -- F_timer = 16MHZ/64 
  TCCR1B |= (1<<CS11)|(1<<CS10) ; 
}

void enableint(){
    sei(); 
}