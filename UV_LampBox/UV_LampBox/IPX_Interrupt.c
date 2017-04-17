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

#define INTERRUPT_200MS 200

volatile int counter = 1;

// 10 ms timer
void init_interrupt_200ms()
{
	// Set the Timer Mode to CTC
	TCCR0A |= (1 << WGM01);

	// Set the value that you want to count to
	OCR0A = 0x26;

	TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vector

	TCCR0B |= (1 << CS02);
	// set prescaler to 256 and start the timer
}

ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt
{
	//event to be executed every 10ms here
	counter ++;
	if(counter >= 100)
	{
		counter = 1;
		//PORTC ^= 1 << 0;
		decrement_clock();
		display_time();
		read_buttons();
	}
}
