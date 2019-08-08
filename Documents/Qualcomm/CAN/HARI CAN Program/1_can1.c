#include"prototype.h"
unsigned int MSG[4];
unsigned char can_test(void)
{
//unsigned int a,b;
//test:
//clear_lcd();
//lcd_str1("TURN ON IGNITION");
//delay(3000);
//key=IOPIN1;
//key=(1<<25) & key;
//if(key)
{
//	clear_lcd();
//	lcd_str1("KEY PASS");
//	delay(2000);
//	TX_from_CAN2(2);
	while(!(RX_in_CAN1()==2));
	clear_lcd();
	lcd_str1("IGNITION ON");
	delay(3000);
	clear_lcd();
	lcd_str1("CHECKING STATUS OF MODULE");
	delay(3000);
//	a=IOPIN0;
//	a=(0x00000010&a);
//	b=IOPIN0;
//	a=(0x00000040&b);
		if((RX_in_CAN1()==2)||(RX_in_CAN1()==5))
		{
		//TX_from_CAN2(2);
		while(!(RX_in_CAN1()==2));
		clear_lcd();
		lcd_str1("BREAK TEST PASS");
		delay(3000);
		//TX_from_CAN2(2);
		while(!(RX_in_CAN1()==5));
		clear_lcd();
		lcd_str1("SEAT BELT PASS");
		delay(3000);
		return 1;
		}
	
//	else if(a == 0 && b == 1)
//	{
//		TX_from_CAN2(2);
//		while(!(RX_in_CAN1()==2));
//		clear_lcd();
//		lcd_str1("BREAK TEST PASS");
//		delay(3000);
//		TX_from_CAN2(2);
//		while(!(RX_in_CAN1()==2));
//		clear_lcd();
//		lcd_str1("SEAT BELT FAIL");
//		delay(3000);
//		return 1;
//	}
//	else if(a == 1 && b == 0)
//	{
//		TX_from_CAN2(2);
//		while(!(RX_in_CAN1()==2));
//		clear_lcd();
//		lcd_str1("BREAK TEST FAIL");
//		delay(3000);
//		TX_from_CAN2(2);
//		while(!(RX_in_CAN1()==2));
//		clear_lcd();
//		lcd_str1("SEAT BELT PASS");
//		delay(3000);
//		return 1;
//	}
//	else if(a == 1 && b == 1)
//	{
//		TX_from_CAN2(2);
//		while(!(RX_in_CAN1()==2));
//		clear_lcd();
//		lcd_str1("BREAK TEST FAIL");
//		delay(3000);
//		TX_from_CAN2(2);
//		while(!(RX_in_CAN1()==2));
//		clear_lcd();
//		lcd_str1("SEAT BELT FAIL");
//		delay(3000);
//		return 1;
//	}
		else
	{
		clear_lcd();
		delay(1000);
		lcd_str1("MODULE TEST FAIL");
		delay(3000);
		return 0;
	}
}
//else
//	{
//	goto test;
//	}
}
void CAN_init(void)
{
	VPBDIV = 0x02;
	PINSEL1 |= (1<<22)|(1<<24)|(1<<26)|(1<<28)|(1<<18)|(1<<16)|(1<<14);
	C1MOD=1 << 0;
	C1BTR=1<<20 | 1<<19 | 1<<18 | 29;
	C1MOD=0;
	C2MOD=1 << 0;
	C2BTR=1<<20 | 1<<19 | 1<<18 | 29;
	C2MOD=0;
}
//void TX_from_CAN2(unsigned int ch)
//{
//	while((C2SR&0x00000004)!=0x00000004);
//	C2TFI1=(1<<18);
//	C2TDA1=ch;
//	C2TID1=0x045;
//	C2CMR=(1<<0)|(1<<5);
//	while((C2GSR & 0x00000008)!=0x00000008);
//}
unsigned int RX_in_CAN1(void)
{
	while((C1SR&0X01));
	MSG[0]=C1RID;
	MSG[1]=C1RDA;
	MSG[2]=C1RDB;
	MSG[3]=C1RFS;
	C1CMR=(1<<2);
	return MSG[1];
}
