/*
 * IPX_Interrupt.h
 *
 * Created: 22.03.2016 20:54:16
 *  Author: Dan
 */ 


#ifndef IPX_INTERRUPT_H_
#define IPX_INTERRUPT_H_

#define clear_display() put_Char_LCD_Display(0x01,0)
void init_interrupt_200ms();

#endif /* IPX_INTERRUPT_H_ */