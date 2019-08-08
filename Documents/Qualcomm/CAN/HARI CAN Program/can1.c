#include "prototype.h"
int main()
{
unsigned char res;
lcd_init();
CAN_init();
clear_lcd();
lcd_str1("CAN TEST CODE");
delay(2000);
clear_lcd();
TEST:
res= can_test();
if(res!=1)
goto TEST;
delay(2000);
while(1)
{
clear_lcd();
lcd_str1("VEHICLE ON");
delay(1000);
}
}