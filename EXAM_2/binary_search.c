#include<stdio.h>
int main()
{
int n,x,i,flag=0,first,last,mid;
	printf("number od elements u need\n");
	scanf("%d",&n);
	int number[n];
	printf("enter the elements in assending order\n");
	for(i=0;i<n;i++)
	scanf("%d",&number[i]);

	printf("entre the number to search\n");
	scanf("%d",&x);
	first=0;
	last=n-1;
	
	while(first<=last)
	{
		mid=(first+last)/2;
		if(x==number[mid])
		{

		flag=1;
		break;
		}
		else
			if(x>number[mid])
			first=mid+1;	
			else
				last=mid-1;
			
	
	}
	if(flag==1)
		printf("element found at position::%d\n",mid+1);
	else
		printf("\nelement not found\n");



}
