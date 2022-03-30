/********************************************
******* Developed by Mohammad Khaled ********
******* Improved  by Mohammad Yousry ********
******* modified: 31/3/2022 12:29:48 AM *****
********* AVR LCD2X16 8-bit & 4-bit *********
**************** File: main.c ***************
*********************************************/

#define F_CPU 12000000UL
#include <xc.h>
#include <util/delay.h>
#include "lcd_interface.h"

int main(void)
{
	LCD4_init();
	
	while(1)
	{
		_delay_ms(1000);
		LCD4_clear();
		LCD4_gotoxy(1,1);
		LCD4_write_string("A7AAAAA");
		LCD4_gotoxy(2, 9);
		LCD4_write_string("a7a");
		
		_delay_ms(1000);
		LCD4_clear();
		LCD4_gotoxy(1,1);
		LCD4_write_string("WTF");
		LCD4_gotoxy(2, 5);
		LCD4_write_string("LOL");
	}
	
}