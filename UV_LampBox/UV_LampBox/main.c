/*
 * UV_LampBox.c
 *
 * Created: 4/14/2017 4:40:44 PM
 * Author : ScorpionIPX
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0xFF;
	PORTD &= 1 << 7;
	PORTD &= 1 << 6;
	
    while (1) 
    {
    }
}

