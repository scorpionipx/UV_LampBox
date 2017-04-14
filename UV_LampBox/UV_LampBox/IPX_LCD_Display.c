/*
 * IPX_LCD_Display.c
 *
 * Created: 22.03.2016 16:53:29
 *  Author: Dan
 */ 

#define  F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define LCD_PORT PORTD
#define LCD_DDR DDRD
#define IPX_LCD_DELAY_MS 10

void put_Char_LCD_Display(int ch, int type)
{
	LCD_PORT = (LCD_PORT&0x0F)|(ch&0xF0);
	LCD_PORT = (LCD_PORT&0xFE)|(type&0x01);
	LCD_PORT = LCD_PORT|0x02;
	_delay_ms(IPX_LCD_DELAY_MS);
	LCD_PORT &= 0xFC;
	LCD_PORT = (LCD_PORT&0x0F)|((ch<<4)&0xF0);
	LCD_PORT = (LCD_PORT&0xFE)|(type&0x01);
	LCD_PORT = LCD_PORT|0x02;
	_delay_ms(IPX_LCD_DELAY_MS);
	LCD_PORT &= 0xFC;
}

void init_LCD_Display(void)
{
	LCD_DDR = 0xFF;
	put_Char_LCD_Display(0x03,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x03,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x03,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x02,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x0D,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x01,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x80,0);
	_delay_ms(IPX_LCD_DELAY_MS);
	put_Char_LCD_Display(0x01,0);//clear display
}
