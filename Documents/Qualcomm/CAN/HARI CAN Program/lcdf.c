#include "prototype.h"	
void delay(int count)
{
	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<1000;j++);
}
void lcd_cmd(int c)
{
	IOCLR0=0xff<<15;
	IOSET0=c<<15;
	IOCLR0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(1000);
	IOCLR0=EN;
}
void lcd_data(char d)
{
	IOCLR0=0xff<<15;
	IOSET0=d<<15;
	IOSET0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(1000);
	IOCLR0=EN;
}
void lcd_init(void )
{
	IODIR0|=port;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void lcd_str1(char a[])
{
	int b=0;
	 char *ptr=a; 
	 while(*ptr)
	 {
			 lcd_data(*ptr);
			 b++;
			 if(b==16)
			 {
				 lcd_cmd(0xc0);
			 }
			 if(b==32)
			 {
				lcd_cmd(0x01);
				lcd_cmd(0x80);
				b=0;
			 }
			 ptr++;
	 }
}
 void lcd_num(int num)
{
	if(num)
	{
		lcd_num(num/10);
		lcd_data((num%10)+0x30);
	}
}
void clear_lcd(void)
{
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
