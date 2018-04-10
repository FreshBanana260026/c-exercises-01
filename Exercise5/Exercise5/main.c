/*
 * Exercise5.c
 *
 * Created: 4/10/2018 11:24:37
 * Author : Patrik
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;								// setting all I/O's in port A as outputs
	DDRB = 0x00;
	PORTA = 0xff;
	
	int check = 0b11111111;						//number for checking the input
	
    for (int n = 2; n < 100; n++)
    {
		int result = 1;							//initially display "boolean" is true
		for (int i = 2; i < sqrt(n+1); i++)
		{
			if (n % i == 0)
			{
				result = 0;						//if the number is dividable, "boolean" is set to false
			}
		}
		if (result)
		{
			while (PINB == check)				//wait until any button is pressed
			{
			}
			PORTA = ~n;							//display inverted number
			_delay_ms(1000);					//wait for a second
		}
    }
}

