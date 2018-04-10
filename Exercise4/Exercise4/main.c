/*
 * Exercise4.c
 *
 * Created: 4/10/2018 10:44:19
 * Author : Patrik
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>

void flicker(int led_no);

int main(void)
{
	DDRA = 0xff;					// setting all I/O's in port A as outputs
	flicker(0);
	flicker(1);
	flicker(2);
	flicker(3);
	flicker(4);
	flicker(5);
	flicker(6);
	flicker(7);
	return 1;
}

void flicker(int led_no){
	PORTA = ~(1<<led_no);			// turning on led 0 (active low)
	_delay_ms(1000);
	PORTA |= (1<<led_no);			// turning on led 1 (active high)
}

