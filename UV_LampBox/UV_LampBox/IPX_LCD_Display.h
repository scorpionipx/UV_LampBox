/*
 * IPX_LCD_Display.h
 *
 * Created: 22.03.2016 17:00:16
 *  Author: Dan
 */ 

/*PIN CONFIGURATION*/
/* D4 -> PD4          */
/* D5 -> PD5          */
/* D6 -> PD6          */
/* D7 -> PD7          */
/* RS -> PD0          */
/* E  -> PD1          */


#ifndef IPX_LCD_DISPLAY_H_
#define IPX_LCD_DISPLAY_H_

void put_string(const char *_string);
void put_Char_LCD_Display(int ch, int type);
void init_LCD_Display(void);
void display_time();

#endif /* IPX_LCD_DISPLAY_H_ */