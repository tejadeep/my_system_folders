#include<stdio.h>
int main()
{
	int num,dup,rem,res=0;
	printf("enter the number\n");
	scanf("%d",&num);
	dup=num;
	for(;num;num=num/10)
	{
	rem=num%10;
	res=res*10+rem;
	}

	
	if(dup==res)
	printf("number is palindrome\n");
	else
	printf("number is not palindrome\n");

}
