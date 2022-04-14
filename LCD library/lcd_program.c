/********************************************
******* Developed by Mohammad Khaled ********
******* Improved  by Mohammad Yousry ********
******* modified: 31/3/2022 12:29:48 AM *****
********* AVR LCD2X16 8-bit & 4-bit *********
************ File: lcd_program.c ************
*********************************************/

#include "lcd_interface.h"

void LCD_cmd(unsigned char cmd)
{
	LCD_DATA = cmd;
	_delay_ms(1);
	ctrl = (0<<rs)|(0<<rw)|(1<<en);
	_delay_ms(1);
	ctrl = (0<<rs)|(0<<rw)|(0<<en);
	_delay_ms(15);
}

void LCD4_cmd(unsigned char cmd)
{
	//before shifting
	LCD_DATA = (cmd & 0xf0);
	_delay_ms(1);
	ctrl = ((ctrl&0xf0)|((0<<rs)|(0<<rw)|(1<<en)));
	_delay_ms(5);
	ctrl = ((ctrl&0xf0)|((0<<rs)|(0<<rw)|(0<<en)));
	_delay_ms(15);
	
	//after shifting
	LCD_DATA = ((cmd<<4) & 0xf0);
	_delay_ms(1);
	ctrl = ((ctrl&0xf0)|((0<<rs)|(0<<rw)|(1<<en)));
	_delay_ms(5);
	ctrl = ((ctrl&0xf0)|((0<<rs)|(0<<rw)|(0<<en)));
	_delay_ms(15);
}

void LCD_init()
{
	LCDDIR_DATA |= 0xFF;
	LCDDIR_CTRL |= ((1<<rs)|(1<<rw)|(1<<en));
	
	LCD_cmd(0x38);
	LCD_cmd(0x01);
	LCD_cmd(0x0E);
	LCD_cmd(0x80);
}

void LCD4_init()
{
	LCDDIR_DATA |= 0xF0;
	LCDDIR_CTRL |= ((1<<rs)|(1<<rw)|(1<<en));
	
	LCD4_cmd(0x33);
	LCD4_cmd(0x02);
	LCD4_cmd(0x28);
	LCD4_cmd(0x0c);
	LCD4_cmd(0x06);
	LCD4_cmd(0x80);
}

void LCD_write(unsigned char data)
{
	LCD_DATA = data;
	ctrl = ((1<<rs)|(0<<rw)|(1<<en));
	_delay_ms(1);
	ctrl = ((1<<rs)|(0<<rw)|(0<<en));
	_delay_ms(15);
}

void LCD4_write(unsigned char data)
{
	//before shifting
	LCD_DATA = (data & 0xf0);
	_delay_ms(1);
	ctrl = ((ctrl&0xf0)|((1<<rs)|(0<<rw)|(1<<en)));
	_delay_ms(5);
	ctrl = ((ctrl&0xf0)|((1<<rs)|(0<<rw)|(0<<en)));
	_delay_ms(15);
	
	//after shifting
	LCD_DATA = ((data<<4) & 0xf0);
	_delay_ms(1);
	ctrl = ((ctrl&0xf0)|((1<<rs)|(0<<rw)|(1<<en)));
	_delay_ms(5);
	ctrl = ((ctrl&0xf0)|((1<<rs)|(0<<rw)|(0<<en)));
	_delay_ms(15);
}

void LCD_write_string(const char *data)
{
	int n=0;
	while(data[n])
	{
		LCD_write(data[n]);
		n++;
		if (n==16)
		{
			LCD_cmd(0xC0);
		}
	}
}

void LCD4_write_string(const char *data)
{
	int n=0;
	while(data[n])
	{
		LCD4_write(data[n]);
		n++;
		if (n==16)
		{
			LCD4_cmd(0xC0);
		}
	}
}

void LCD_gotoxy(int x, int y)
{
	if (x==1)
	{
		LCD_cmd(0x80);
		for (int i=1;i<y;i++)
		{
			LCD_cmd(0x06);
		}
	}
	if (x==2)
	{
		LCD_cmd(0xC0);
		for (int i=1;i<y;i++)
		{
			LCD_cmd(0x06);
		}
	}
}

void LCD4_gotoxy(int x, int y)
{
	y--;
	if (x==1)
	{
		LCD4_cmd(0x80+y);
	}
	if (x==2)
	{
		LCD4_cmd(0xC0+y);
	}
}

void LCD_clear()
{
	LCD_cmd(0x01);
}

void LCD4_clear()
{
	LCD4_cmd(0x01);
}
