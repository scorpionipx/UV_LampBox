/*
 * IPX_Interrupt.c
 *
 * Created: 22.03.2016 20:52:05
 *  Author: Dan
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "IPX_Clock.h"
#include "IPX_LCD_Display.h"
#include "IPX_UV_light_control.h"
#include "IPX_Buttons.h"

#define INTERRUPT_200MS 200                   // INTERRUT ENTITY

volatile int counter = 1;                     // GENERAL PURPOSE INTERRUPT COUNTER
volatile unsigned short btn_counter = 1;      // BUTTONS INTERRUPT COUNTER 

// 10 ms timer
void init_interrupt_200ms()
{
	TCCR0A |= (1 << WGM01);     // Set the Timer Mode to CTC
	
	OCR0A = 0x26;               // Set the value to count to

	TIMSK0 |= (1 << OCIE0A);    // Set the ISR COMPA vector

	TCCR0B |= (1 << CS02);      // set prescaler to 256
}

ISR (TIMER0_COMPA_vect)  // TIMER0 COMPARE INTERRUPT
{
	// events to be executed every 10ms
	counter ++;
	if(BUTTONS_ALLOWED)
	{
		read_buttons();
	}
	else
	{
		btn_counter ++;
		if(btn_counter >= BUTTONS_DELAY)
		{
			btn_counter = 1;
			BUTTONS_ALLOWED = TRUE;
			PRESSED_BUTTON = NO_BUTTON;
		}
	}
	if(counter >= 99)
	{
		PORTC ^= 1 << 0;
		counter = 1;
		if(STATE_MACHINE == STATE_WORKING)
		{
			display_time();
			decrement_clock();
		}
		PORTC ^= 1 << 0;
	}
}
