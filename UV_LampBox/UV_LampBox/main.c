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
#include "IPX_UV_light_control.h"
#include "IPX_Buttons.h"
#include "IPX_Clock.h"


int main(void)
{
	DDRC |= 1 << 0;   // FEEDBACK LED INIT
	PORTC |= 1 << 0;  // FEEDBACK LED ON
	
	STATE_MACHINE = STATE_INIT;
	PRESSED_BUTTON = NO_BUTTON;
	BUTTONS_ALLOWED = TRUE;
	
	CLOCK.H = 0;
	CLOCK.M = 0;
	CLOCK.S = 0;
	
	CURSON_POSITION = CP_HOURS_X_10;
	
	UV_control_init();
	init_buttons();
	init_interrupt_200ms();
	
	_delay_ms(1200);
	
	init_LCD_Display();
	
	_delay_ms(1200);
	
	put_string("Initializing...");
	
	_delay_ms(1000);
	clear_display();
	
	STATE_MACHINE = STATE_WELCOME;
	
	put_Char_LCD_Display(0x80, 0);
	put_string("ScorpionIPX");
	
	put_Char_LCD_Display(0xC0, 0);
	put_string("UV LampBox v1.0");
	
	_delay_ms(4000);
	PORTC &= ~(1 << 0);
	clear_display();
	
	STATE_MACHINE = STATE_SETTINGS;
	BLINK_ON;
	put_Char_LCD_Display(0x80, 0);
	put_string("SET TIME:");
	
	display_time();
	put_Char_LCD_Display(0xC0, 0);
	_delay_ms(300);
	
	sei();
	
    while (1) 
    {
			
    }
}

