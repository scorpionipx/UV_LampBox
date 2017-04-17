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
	
	STATE_MACHINE = STATE_INIT;
	
	CLOCK.H = 0;
	CLOCK.M = 1;
	CLOCK.S = 11;
	
	UV_control_init();
	init_interrupt_200ms();
	
	DDRC |= 1 << 0;
	PORTC |= 1 << 0;
	
	_delay_ms(1200);
	
	init_LCD_Display();
	
	_delay_ms(1200);
	
	put_string("Initializing...");
	
	_delay_ms(1000);
	clear_display();
	
	put_Char_LCD_Display(0x80, 0);
	put_string("ScorpionIPX");
	
	put_Char_LCD_Display(0xC0, 0);
	put_string("UV LightBox v1.0");
	
	_delay_ms(7000);
	clear_display();
	
	put_Char_LCD_Display(0x80, 0);
	put_string("TIME:");
	
	display_time();
	
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

