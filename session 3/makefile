default: app.bin
	avr-objcopy -O ihex -R .eeprom app.bin app.hex

flash: app.hex
	avrdude -F -V -c arduino -p atmega328p -P /dev/ttyUSB0 -b 115200 -U flash:w:app.hex:i

servohal.o: servohal.c servohal.h
	avr-gcc -mmcu=atmega328p -c servohal.c -o servohal.o

app.o: app.c servohal.h
	avr-gcc -mmcu=atmega328p -c app.c -o app.o

app.bin: servohal.o app.o
	avr-gcc -mmcu=atmega328p app.o servohal.o -o app.bin

clean:
	-rm *.o
	-rm *.bin
	-rm *.hex
