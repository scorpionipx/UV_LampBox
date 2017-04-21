/*
 * IPX_LCD_Display.c
 *
 * Created: 22.03.2016 16:53:29
 *  Author: Dan
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "IPX_LCD_Display.h"

#define MAX_CHARS_PER_ROW 16   // 16X2 LCD DISPLAY PROPERTIES
#define LCD_DELAY_MS 2         // DELAY BETWEEN DATA SENT TO LCD
#define LCD_INIT_DELAY_MS 7    // DELAY BETWEEN DATA SENT TO LCD WHEN INITIALIZING

// SEND COMMAND OR DATA TO LCD, 4 BIT MODE CONFIGURATION
// type == 1 => SEND DATA
// type == 0 => SEND COMMAND 
void put_Char_LCD_Display(int ch, int type)
{
	PORTD = (PORTD&0x0F)|(ch&0xF0);
	PORTD = (PORTD&0xFE)|(type&0x01);
	PORTD = PORTD|0x02;
	_delay_ms(LCD_DELAY_MS);
	PORTD &= 0xFC;
	PORTD = (PORTD&0x0F)|((ch<<4)&0xF0);
	PORTD = (PORTD&0xFE)|(type&0x01);
	PORTD = PORTD|0x02;
	_delay_ms(LCD_DELAY_MS);
	PORTD &= 0xFC;
}

// LCD INITIALIZING FOR 4 BIT MODE
void init_LCD_Display(void)
{
	DDRD = 0xFF;
	put_Char_LCD_Display(0x38,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x38,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x38,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x02,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x0C,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x01,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x80,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x01,0);//clear display
}

// DISPLAY STRING ON LCD
void put_string(const char *_string)
{
	int ch_index;
	for(ch_index=0;ch_index<strlen(_string);ch_index++)
	{
		put_Char_LCD_Display(_string[ch_index], 1);
	}
}

// DISPLAY CURRENT TIME
void display_time()
{
	put_Char_LCD_Display(0xC0, 0);
	put_Char_LCD_Display('0' + CLOCK.H/10, 1);
	put_Char_LCD_Display('0' + CLOCK.H%10, 1);
	put_Char_LCD_Display(':', 1);
	put_Char_LCD_Display('0' + CLOCK.M/10, 1);
	put_Char_LCD_Display('0' + CLOCK.M%10, 1);
	put_Char_LCD_Display(':', 1);
	put_Char_LCD_Display('0' + CLOCK.S/10, 1);
	put_Char_LCD_Display('0' + CLOCK.S%10, 1);
}
