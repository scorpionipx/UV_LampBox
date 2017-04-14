/*
 * UV_LampBox.c
 *
 * Created: 4/14/2017 4:40:44 PM
 * Author : ScorpionIPX
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRC |= 1 << 0;
	PORTC |= 1 << 0;
	
    while (1) 
    {
		_delay_ms(1000);
		PORTC ^= 1 << 0;
		
    }
}

