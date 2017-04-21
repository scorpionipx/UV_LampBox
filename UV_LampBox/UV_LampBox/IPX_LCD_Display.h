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

#define BLINK_ON put_Char_LCD_Display(0x0D, 0)         // ACTIVATE CURSOR BLINKING
#define BLINK_OFF put_Char_LCD_Display(0x0C, 0)        // DEACTIVATE CURSOR BLINKING
#define clear_display() put_Char_LCD_Display(0x01,0)   // CLEAR LCD DISPLAY AND LCD RAM

#endif /* IPX_LCD_DISPLAY_H_ */