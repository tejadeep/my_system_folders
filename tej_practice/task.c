#include<stdio.h>
int main()
{
	int a,b,res,i;
	printf("enter the divisor\n");
	scanf("%d",&a);
	l1:
	printf("enter the divider\n");
	scanf("%d",&b);
	if(b==0)
	{
	printf("please give other value exept zero because it gives an floating point error\n");
	goto l1;
	} 
	while(a)
	{
	if(a<b)
	break;
	a=a-b;
	}
	
	printf("remainder is %d\n",a);

}
