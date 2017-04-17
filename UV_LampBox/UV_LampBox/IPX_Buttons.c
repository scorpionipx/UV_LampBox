/*
 * IPX_Buttons.c
 *
 * Created: 4/17/2017 1:16:52 PM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include "IPX_Buttons.h"
#include "IPX_LCD_Display.h"
#include "IPX_Clock.h"
#include "IPX_UV_light_control.h"

void init_buttons()
{
	BUTTONS_DDR &= ~(1 << BUTTON_1_PIN | 1 << BUTTON_2_PIN | 1 << BUTTON_3_PIN | 1 << BUTTON_4_PIN);
	BUTTONS_PORT &= ~(1 << BUTTON_1_PIN | 1 << BUTTON_2_PIN | 1 << BUTTON_3_PIN | 1 << BUTTON_4_PIN);
	
	BUTTON_1_PRESSED = FALSE;
	BUTTON_2_PRESSED = FALSE;
	BUTTON_3_PRESSED = FALSE;
	BUTTON_4_PRESSED = FALSE;
}

void read_buttons()
{
	BUTTON_1_PRESSED = BUTTON_1_VALUE;
	if(BUTTON_1_PRESSED)
	{
		PRESSED_BUTTON = BUTTON_1;
		BUTTONS_ALLOWED = FALSE;
		
		switch(STATE_MACHINE)
		{
			case STATE_SETTINGS:
			{
				set_cursor(LEFT);
				break;
			}
			
			case STATE_FINISHED:
			{
				STATE_MACHINE = STATE_SETTINGS;
				BLINK_ON;
				clear_display();
				put_Char_LCD_Display(0x80, 0);
				put_string("SET TIME:");
				
				CLOCK.S = CLOCK.M = CLOCK.H = 0;
				
				display_time();
				put_Char_LCD_Display(0xC0, 0);
				break;
			}
			
			case STATE_WORKING:
			{
				STATE_MACHINE = STATE_PAUSE;
				UV_CONTROL_OFF;
				put_Char_LCD_Display(0x80, 0);
				BLINK_ON;
				put_string("PAUSED     ");
				put_Char_LCD_Display(0x80 + 7, 0);
				break;
			}
			
			case STATE_PAUSE:
			{
				STATE_MACHINE = STATE_SETTINGS;
				BLINK_ON;
				clear_display();
				put_Char_LCD_Display(0x80, 0);
				put_string("SET TIME:");
				
				CLOCK.S = CLOCK.M = CLOCK.H = 0;
				
				display_time();
				put_Char_LCD_Display(0xC0, 0);
				break;
			}
		}
		
		return;
	}
	
	BUTTON_2_PRESSED = BUTTON_2_VALUE;
	if(BUTTON_2_PRESSED)
	{
		PRESSED_BUTTON = BUTTON_2;
		BUTTONS_ALLOWED = FALSE;
		
		switch(STATE_MACHINE)
		{
			case STATE_SETTINGS:
			{
				set_cursor(RIGHT);
				break;
			}
			
			case STATE_FINISHED:
			{
				STATE_MACHINE = STATE_SETTINGS;
				BLINK_ON;
				clear_display();
				put_Char_LCD_Display(0x80, 0);
				put_string("SET TIME:");
				
				CLOCK.S = CLOCK.M = CLOCK.H = 0;
				
				display_time();
				put_Char_LCD_Display(0xC0, 0);
				break;
			}
			
			case STATE_WORKING:
			{
				STATE_MACHINE = STATE_PAUSE;
				UV_CONTROL_OFF;
				put_Char_LCD_Display(0x80, 0);
				BLINK_ON;
				put_string("PAUSED     ");
				put_Char_LCD_Display(0x80 + 7, 0);
				break;
			}
	
			case STATE_PAUSE:
			{
				STATE_MACHINE = STATE_SETTINGS;
				BLINK_ON;
				clear_display();
				put_Char_LCD_Display(0x80, 0);
				put_string("SET TIME:");
		
				CLOCK.S = CLOCK.M = CLOCK.H = 0;
		
				display_time();
				put_Char_LCD_Display(0xC0, 0);
				break;
			}
		}
		
		return;
	}
	
	BUTTON_3_PRESSED = BUTTON_3_VALUE;
	if(BUTTON_3_PRESSED)
	{
		PRESSED_BUTTON = BUTTON_3;
		BUTTONS_ALLOWED = FALSE;
		
		switch(STATE_MACHINE)
		{
			case STATE_SETTINGS:
			{
				set_time(DECREASE_TIME);
				break;
			}
			
			case STATE_FINISHED:
			{
				STATE_MACHINE = STATE_SETTINGS;
				BLINK_ON;
				clear_display();
				put_Char_LCD_Display(0x80, 0);
				put_string("SET TIME:");
				
				CLOCK.S = CLOCK.M = CLOCK.H = 0;
				
				display_time();
				put_Char_LCD_Display(0xC0, 0);
				break;
			}
			
			case STATE_WORKING:
			{
				STATE_MACHINE = STATE_PAUSE;
				UV_CONTROL_OFF;
				put_Char_LCD_Display(0x80, 0);
				BLINK_ON;
				put_string("PAUSED     ");
				put_Char_LCD_Display(0x80 + 7, 0);
				break;
			}
			
			case STATE_PAUSE:
			{
				put_Char_LCD_Display(0x80, 0);
				put_string("WORKING...    ");
				CURSON_POSITION = CP_HOURS_X_10;
				BLINK_OFF;
				STATE_MACHINE = STATE_WORKING;
				UV_CONTROL_ON;
				break;
			}
		}
		
		return;
	}
	
	BUTTON_4_PRESSED = BUTTON_4_VALUE;
	if(BUTTON_4_PRESSED)
	{
		PRESSED_BUTTON = BUTTON_4;
		BUTTONS_ALLOWED = FALSE;
		
		switch(STATE_MACHINE)
		{
			case STATE_SETTINGS:
			{
				set_time(INCREASE_TIME);
				break;
			}
			
			case STATE_FINISHED:
			{
				STATE_MACHINE = STATE_SETTINGS;
				BLINK_ON;
				clear_display();
				put_Char_LCD_Display(0x80, 0);
				put_string("SET TIME:");
				
				CLOCK.S = CLOCK.M = CLOCK.H = 0;
				
				display_time();
				put_Char_LCD_Display(0xC0, 0);
				break;
			}
			
			case STATE_WORKING:
			{
				STATE_MACHINE = STATE_PAUSE;
				UV_CONTROL_OFF;
				put_Char_LCD_Display(0x80, 0);
				BLINK_ON;
				put_string("PAUSED     ");
				put_Char_LCD_Display(0x80 + 7, 0);
				break;
			}
			
			case STATE_PAUSE:
			{				
				put_Char_LCD_Display(0x80, 0);
				put_string("WORKING...    ");
				CURSON_POSITION = CP_HOURS_X_10;
				BLINK_OFF;
				STATE_MACHINE = STATE_WORKING;
				UV_CONTROL_ON;
				break;
			}
		}
		
		return;
	}
	
	PRESSED_BUTTON = NO_BUTTON;
}
