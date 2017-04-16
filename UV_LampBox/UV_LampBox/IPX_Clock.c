/*
 * IPX_Clock.c
 *
 * Created: 4/16/2017 11:42:12 PM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"

void decrement_clock()
{
	if(CLOCK.S >= 1)
	{
		CLOCK.S --;
	}
	else
	{
		CLOCK.S = 59;
		if(CLOCK.M >= 1)
		{
			CLOCK.M --;
		}
		else
		{
			CLOCK.M = 59;
			if(CLOCK.H >= 1)
			{
				CLOCK.H --;
			}
		}
	}
	
}