#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define F_CPU		1000000UL // 1MHz internal RC oscillator; clock freq-must be define before including util/delay.h

#define FALSE 0 // LOGIC FALSE
#define TRUE 1  // LOGIC TRUE

#define STATE_INIT 0      // MACHINE STATE - INITIALIZATION
#define STATE_WELCOME 1   // MACHINE STATE - WELCOME MESSAGE
#define STATE_PASSWROD 2  // MACHINE STATE - INSERT PASSWORD
#define STATE_SETTINGS 3  // MACHINE STATE - SET TIME FOR UV LAMP
#define STATE_WORKING 4   // MACHINE STATE - UV LAMP ON
#define STATE_PAUSE 5     // MACHINE STATE - TIMER PAUSED, WAIT FOR RESUME OR STOP
#define STATE_FINISHED 6  // MACHINE STATE - TIMER REACHED ZERO, WAIT FOR ANY INPUT; GOES TO STATE_SETTINGS



// types
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/
unsigned short STATE_MACHINE;     // VAR USED TO TRACK STATE MACHINE
unsigned short PRESSED_BUTTON;    // VAR USED TO TRACK CURRENTLY PRESSED BUTTON
unsigned short CURSON_POSITION;   // VAR TO TRACK CURSOR POSITION USED TO MODIFY CLOCK's VALUES

// STRUCT FOR TIME TRACKING
struct clock_struct
{
	short int H;
	short int M;
	short int S;
	}CLOCK;

// GLOBAL STRUCT FOR BOOLEAN VARIABLES; USE BIT FIELDS TO IMPROVE MEMORY USAGE
struct boolean_struct
{
	unsigned int BOOL_0 : 1;
	unsigned int BOOL_1 : 1;
	unsigned int BOOL_2 : 1;
	unsigned int BOOL_3 : 1;
	unsigned int BOOL_4 : 1;
	unsigned int BOOL_5 : 1;
	unsigned int BOOL_6 : 1;
	unsigned int BOOL_7 : 1;
	}GLOBAL_BOOL;

#define BUTTON_1_PRESSED GLOBAL_BOOL.BOOL_0   // BUTTON ONE PRESSED
#define BUTTON_2_PRESSED GLOBAL_BOOL.BOOL_1   // BUTTON TWO PRESSED
#define BUTTON_3_PRESSED GLOBAL_BOOL.BOOL_2   // BUTTON THREE PRESSED
#define BUTTON_4_PRESSED GLOBAL_BOOL.BOOL_3   // BUTTON FOUR PRESSED

#define BUTTONS_ALLOWED GLOBAL_BOOL.BOOL_4

#define NO_BUTTON 0 // NO BUTTON ENTITY

#define BUTTON_1 1  // BUTTON ONE ENTITY
#define BUTTON_2 2  // BUTTON TWO ENTITY
#define BUTTON_3 3  // BUTTON THREE ENTITY
#define BUTTON_4 4  // BUTTON FOUR ENTITY

#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
