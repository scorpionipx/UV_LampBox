/*
 * IPX_UV_light_control.c
 *
 * Created: 4/17/2017 2:01:41 AM
 *  Author: ScorpionIPX
 */ 

#include "IPX_UV_light_control.h"
#include <avr/io.h>

void UV_control_init()
{
	UV_CONTROL_DDR |= 1 << UV_CONTROL_PIN;
	UV_CONTROL_OFF;
}