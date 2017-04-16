#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define F_CPU		1000000UL //clock freq-must be define before including util/delay.h

#define FALSE 0
#define TRUE 1


// types
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/
char MENU;

#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
