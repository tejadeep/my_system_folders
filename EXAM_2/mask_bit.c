#include<stdio.h>
int main()
{
	int num,pos,bit;
	printf("enter the number\n");
	scanf("%d",&num);
	printf("enter the nth bit to mask\n");
	scanf("%d",&bit);
	pos=sizeof(num)*8-1;
	for(;pos>=0;pos--)
	{	
	printf("%d",num>>pos&1);
	
	}

	pos=sizeof(num)*8-1;
	
	for(;pos>=0;pos--)
	{
	if(bit==(pos))
	{
	num=num&~(1<<(pos-1));	
	
	}
	}
	printf("\n");
	pos=sizeof(num)*8-1;
	
	for(;pos>=0;pos--)
	printf("%d",num>>pos&1);

	printf("\nie., number=%d",num);
	
	
	printf("\n");
	
}
