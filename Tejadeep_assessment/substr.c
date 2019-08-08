#include<stdio.h>
int main()
{
//	char a[]="I live in hyderabad and my office is in hyderabad";
	char a[]="hyderabad hyderabad";
	char b[10];
	int i,j,count=0;
	printf("enter the substring\n");
	scanf("%s",b);

	for(i=0;a[i];i++)
	{
		if(b[0]==a[i])
		{
		i++;
		for(j=1;b[j];j++,i++)
		{
		if(b[j]!=a[i])
		break;
		}
		if(b[j]=='\0')
		{
		count++;
//		printf("present....\n");
		}
		
	
	
		}
		
	
	
	} 

	printf("count of substring present in given string is ::: %d\n",count);

}
