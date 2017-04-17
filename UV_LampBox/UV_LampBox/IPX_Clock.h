/*
 * IPX_Clock.h
 *
 * Created: 4/16/2017 11:45:26 PM
 *  Author: ScorpionIPX
 */ 


#ifndef IPX_CLOCK_H_
#define IPX_CLOCK_H_

#define CP_HOURS_X_10 0     // CURSOR POSITION HOUR x 10
#define CP_HOURS 1          // CURSOR POSITION HOUR
#define CP_MINUTES_X_10 3   // CURSOR POSITION MINUTE x 10
#define CP_MINUTES 4        // CURSOR POSITION MINUTE
#define CP_SECONDS_X_10 6   // CURSOR POSITION SECOND x 10
#define CP_SECONDS 7        // CURSOR POSITION SECOND

#define INCREASE_TIME 1     // COEFICIENT FOR TIME INCREMENT
#define DECREASE_TIME (-1)  // COEFICIENT FOR TIME DECREMENT

#define LEFT (-1)  // COEFICIENT TO MOVE CURSOR RO LEFT
#define RIGHT 1    // COEFICIENT TO MOVE CURSOR RO LEFT

void decrement_clock();
void set_time();
void set_cursor(int direction);


#endif /* IPX_CLOCK_H_ */