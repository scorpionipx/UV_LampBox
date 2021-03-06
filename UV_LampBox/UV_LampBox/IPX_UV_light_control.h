/*
 * IPX_UV_light_control.h
 *
 * Created: 4/17/2017 2:02:54 AM
 *  Author: ScorpionIPX
 */ 

/*
	PIN CONFIGURATION
	
	RELAY SWITCH -> PC1, 24th
*/

#ifndef IPX_UV_LIGHT_CONTROL_H_
#define IPX_UV_LIGHT_CONTROL_H_

#include "avr/io.h"

#define UV_CONTROL_DDR DDRC
#define UV_CONTROL_PORT PORTC
#define UV_CONTROL_PIN PC1

#define UV_CONTROL_ON UV_CONTROL_PORT |= 1 << UV_CONTROL_PIN         // TURN ON UV LAMP
#define UV_CONTROL_OFF UV_CONTROL_PORT &= ~(1 << UV_CONTROL_PIN)     // TURN OFF UV LAMP
#define UV_CONTROL_TOGGLE UV_CONTROL_PORT ^= 1 << UV_CONTROL_PIN     // TOGGLE UV LAMP, USED FOR TESTING


void UV_control_init();

#endif /* IPX_UV_LIGHT_CONTROL_H_ */