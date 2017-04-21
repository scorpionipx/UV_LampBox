/*
 * IPX_Clock.c
 *
 * Created: 4/16/2017 11:42:12 PM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include "IPX_Clock.h"
#include "IPX_LCD_Display.h"
#include "IPX_UV_light_control.h"

// DECREASE TIME BY ONE SECOND
// IF TIME IS REACHES 00:00:00, STATE MACHINE CHANGES TO WORK FINISHED
void decrement_clock()
{
	if(CLOCK.S >= 1)
	{
		CLOCK.S --;
	}
	else
	{
		if(CLOCK.S == 0 && CLOCK.M == 0 && CLOCK.H ==0)
		{
			UV_CONTROL_OFF;
			STATE_MACHINE = STATE_FINISHED;
			clear_display();
			put_string("WORK FINISHED");
			put_Char_LCD_Display(0xC0, 0);
			put_string("PRESS ANY KEY");
		}
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

// SET NEW TIME VALUE FOR UV LAMP
void set_time(int increase_decrease)
{
	switch(CURSON_POSITION)
	{
		case CP_HOURS_X_10:
		{
			CLOCK.H += increase_decrease * 10;
			if(CLOCK.H > 99)
			{
				CLOCK.H = 99;
			}
			if(CLOCK.H < 0)
			{
				CLOCK.H = 0;
			}
			break;
		}
		
		case CP_HOURS:
		{
			CLOCK.H += increase_decrease;
			if(CLOCK.H > 99)
			{
				CLOCK.H = 99;
			}
			if(CLOCK.H < 0)
			{
				CLOCK.H = 0;
			}
			break;
		}
		
		case CP_MINUTES_X_10:
		{
			CLOCK.M += increase_decrease * 10;
			if(CLOCK.M > 59)
			{
				CLOCK.M = 59;
			}
			if(CLOCK.M < 0)
			{
				CLOCK.M = 0;
			}
			break;
		}
		
		case CP_MINUTES:
		{
			CLOCK.M += increase_decrease;
			if(CLOCK.M > 99)
			{
				CLOCK.M = 99;
			}
			if(CLOCK.M < 0)
			{
				CLOCK.M = 0;
			}
			break;
		}

		case CP_SECONDS_X_10:
		{
			CLOCK.S += increase_decrease * 10;
			if(CLOCK.S > 59)
			{
				CLOCK.S = 59;
			}
			if(CLOCK.S < 0)
			{
				CLOCK.S = 0;
			}
			break;
		}
		
		case CP_SECONDS:
		{
			CLOCK.S += increase_decrease;
			if(CLOCK.S > 59)
			{
				CLOCK.S = 59;
			}
			if(CLOCK.S < 0)
			{
				CLOCK.S = 0;
			}
			break;
		}
	}
	
	display_time();
	put_Char_LCD_Display(0xC0 + CURSON_POSITION, 0);
}

// SHIFT CURSOR TO ANOTHER DIGIT
// SELECTED DIGIT IS THE ONE WHICH IS MODIFIED
// MOVING CURSOR FURTHER RIGHT AFTER SECONDS LAST DIGIT RESULTS IN STARTING UP THE UV LAMP
void set_cursor(int direction)
{
	switch(direction)
	{
		case LEFT:
		{
			CURSON_POSITION --;
			if(CURSON_POSITION == 2 || CURSON_POSITION == 5)
			{
				CURSON_POSITION --;
			}
			if(CURSON_POSITION < CP_HOURS_X_10)
			{
				CURSON_POSITION = CP_HOURS_X_10;
			}
			break;
		}
		
		case RIGHT:
		{
			CURSON_POSITION ++;
			if(CURSON_POSITION == 2 || CURSON_POSITION == 5)
			{
				CURSON_POSITION ++;
			}
			if(CURSON_POSITION > CP_SECONDS)
			{
				put_Char_LCD_Display(0x80, 0);
				put_string("WORKING...");
				CURSON_POSITION = CP_HOURS_X_10;
				BLINK_OFF;
				STATE_MACHINE = STATE_WORKING;
				UV_CONTROL_ON;
			}
			break;
		}
	}
	display_time();
	put_Char_LCD_Display(0xC0 + CURSON_POSITION, 0);
}