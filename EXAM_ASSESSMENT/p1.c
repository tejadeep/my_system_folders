//reverse the integer number

#include<stdio.h>
int main()
{
	int num,rem,i,res=0;
	printf("enter the number\n");
	scanf("%d",&num);
	printf("befor::%d\n",num);
	for(i=0;num;num=num/10)
	{
	rem=num%10;
	res=res*10 +rem;
	

	}
	printf("after ::: %d\n",res);



}
