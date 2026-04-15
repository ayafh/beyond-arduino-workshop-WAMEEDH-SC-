#define PINMASK(x) (1 << x)

void setup(){
  
  DDRB |= PINMASK(5); /* pinMode(13, OUTPUT); */
}

void smalldelay(){
  for (uint32_t volatile i =0 ; i<0x000FFFFF ; i++);
}

void loop(){
  
  PORTB |= PINMASK(5); /* digitalWrite(13, HIGH) */
  smalldelay();
  PORTB &= ~PINMASK(5); 
  smalldelay();
}
