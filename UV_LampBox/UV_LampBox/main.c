/*
 * UV_LampBox.c
 *
 * Created: 4/14/2017 4:40:44 PM
 * Author : ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "IPX_LCD_Display.h"
#include "IPX_Interrupt.h"


int main(void)
{
    /* Replace with your application code */
	
	CLOCK.H = 0;
	CLOCK.M = 1;
	CLOCK.S = 11;
	init_interrupt_200ms();
	DDRC |= 1 << 0;
	PORTC |= 1 << 0;
	_delay_ms(1200);
	init_LCD_Display();
	_delay_ms(1200);
	put_Char_LCD_Display('I', 1);
	put_Char_LCD_Display('n', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('t', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('a', 1);
	put_Char_LCD_Display('l', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('z', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('n', 1);
	put_Char_LCD_Display('g', 1);
	put_Char_LCD_Display('.', 1);
	put_Char_LCD_Display('.', 1);
	put_Char_LCD_Display('.', 1);
	
	_delay_ms(1000);
	put_Char_LCD_Display(0x01,0);//clear display
	
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
	put_Char_LCD_Display('U', 1);
	put_Char_LCD_Display('V', 1);
	put_Char_LCD_Display(' ', 1);
	put_Char_LCD_Display('L', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('g', 1);
	put_Char_LCD_Display('h', 1);
	put_Char_LCD_Display('t', 1);
	put_Char_LCD_Display('B', 1);
	put_Char_LCD_Display('o', 1);
	put_Char_LCD_Display('x', 1);
	put_Char_LCD_Display(' ', 1);
	put_Char_LCD_Display('v', 1);
	put_Char_LCD_Display('1', 1);
	put_Char_LCD_Display('.', 1);
	put_Char_LCD_Display('0', 1);
	_delay_ms(7000);
	put_Char_LCD_Display(0x01,0);//clear display
	
	put_Char_LCD_Display(0x80, 0);
	put_Char_LCD_Display('T', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('m', 1);
	put_Char_LCD_Display('e', 1);
	put_Char_LCD_Display(':', 1);
	
	put_Char_LCD_Display(0xC0, 0);
	put_Char_LCD_Display('0' + CLOCK.H/10, 1);
	put_Char_LCD_Display('0' + CLOCK.H%10, 1);
	put_Char_LCD_Display(':', 1);
	put_Char_LCD_Display('0' + CLOCK.M/10, 1);
	put_Char_LCD_Display('0' + CLOCK.M%10, 1);
	put_Char_LCD_Display(':', 1);
	put_Char_LCD_Display('0' + CLOCK.S/10, 1);
	put_Char_LCD_Display('0' + CLOCK.S%10, 1);
	sei();
	
	_delay_ms(1000);
    while (1) 
    {
		/*_delay_ms(100);
		PORTC ^= 1 << 0;
		_delay_ms(5000);
		PORTC ^= 1 << 0;*/
		
    }
}

