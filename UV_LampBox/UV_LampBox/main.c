/*
 * UV_LampBox.c
 *
 * Created: 4/14/2017 4:40:44 PM
 * Author : ScorpionIPX
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "IPX_LCD_Display.h"


int main(void)
{
    /* Replace with your application code */
	DDRC |= 1 << 0;
	PORTC |= 1 << 0;
	_delay_ms(200);
	init_LCD_Display();
	put_Char_LCD_Display('t', 1);
	put_Char_LCD_Display('e', 1);
	put_Char_LCD_Display('s', 1);
	put_Char_LCD_Display('t', 1);
	put_Char_LCD_Display(' ', 1);
	put_Char_LCD_Display('t', 1);
	put_Char_LCD_Display('e', 1);
	put_Char_LCD_Display('s', 1);
	put_Char_LCD_Display('t', 1);
	
	put_Char_LCD_Display(0x80, 0);
	put_Char_LCD_Display('S', 1);
	put_Char_LCD_Display('c', 1);
	put_Char_LCD_Display('o', 1);
	put_Char_LCD_Display('r', 1);
	put_Char_LCD_Display('p', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('o', 1);
	put_Char_LCD_Display('n', 1);
	put_Char_LCD_Display('I', 1);
	put_Char_LCD_Display('P', 1);
	put_Char_LCD_Display('X', 1);
	
	put_Char_LCD_Display(0xC0, 0);
	
	_delay_ms(1000);
    while (1) 
    {
		_delay_ms(500);
		PORTC ^= 1 << 0;
		
    }
}

