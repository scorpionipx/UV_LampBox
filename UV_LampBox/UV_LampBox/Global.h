#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define F_CPU		1000000UL // 1MHz internal RC oscillator; clock freq-must be define before including util/delay.h

#define FALSE 0
#define TRUE 1

#define PRESSED 1
#define RELEASED 0

#define STATE_INIT 0
#define STATE_WELCOME 1
#define STATE_PASSWROD 2
#define STATE_SETTINGS 3
#define STATE_WROKING 4
#define STATE_PAUSE 5
#define STATE_FINISHED 6



// types
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/
unsigned short STATE_MACHINE;
unsigned short PRESSED_BUTTON;
struct clock_struct
{
	unsigned short int H;
	unsigned short int M;
	unsigned short int S;
	}CLOCK;

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

#define BUTTON_1_PRESSED GLOBAL_BOOL.BOOL_0 
#define BUTTON_2_PRESSED GLOBAL_BOOL.BOOL_1 
#define BUTTON_3_PRESSED GLOBAL_BOOL.BOOL_2 
#define BUTTON_4_PRESSED GLOBAL_BOOL.BOOL_3 

#define NO_BUTTON 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4

#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
