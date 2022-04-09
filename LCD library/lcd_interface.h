/********************************************
******* Developed by Mohammad Khaled ********
******* Improved  by Mohammad Yousry ********
******* modified: 31/3/2022 12:29:48 AM *****
********* AVR LCD2X16 8-bit & 4-bit *********
*********** File: lcd_interface.h ***********
*********************************************/

#include <avr/io.h>
#include <util/delay.h>

#ifndef LCD_INT_H
#define LCD_INT_H

#define LCDDIR_DATA   DDRB  //warning : for 4 bit connection, always use the last 4 pins of any port
#define LCD_DATA      PORTB
#define LCDDIR_CTRL   DDRB  //you can use any remaining pins of any port for the control
#define ctrl      PORTB
#define rs        PINB0
#define rw        PINB1
#define en        PINB2

void LCD_cmd(unsigned char); 
void LCD4_cmd(unsigned char);
void LCD_init();
void LCD4_init();
void LCD_write(unsigned char);
void LCD4_write(unsigned char);
void LCD_write_string(const char*);
void LCD4_write_string(const char*);
void LCD_gotoxy(int, int);
void LCD4_gotoxy(int, int);
void LCD_clear();
void LCD4_clear();

#endif
