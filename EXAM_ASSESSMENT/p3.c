//program to reset a bit 
#include<stdio.h>
int main()
{
	int num,p,num2;
	printf("enter the number\n");
	scanf("%d",&num);
	printf("enter the position to reset");
	scanf("%d",&num2);
	p=sizeof(int)*8-1;
	printf("before\n");
	for(;p>=0;p--)
	{

	printf("%d ",num>>p&1);
	
	if(num2==(p+1))
	{
	num=num&~(1<<p);
	
	}
	}
	printf("\n");
	p=sizeof(int)*8-1;
	printf("after::\n");
	for(;p>=0;p--)
	{

	printf("%d ",num>>p&1);
	}
	printf("\n");
	

}
