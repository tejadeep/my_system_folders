//progrom to copy one array to other array

#include<stdio.h>
int main()
{
	int i,j,n;
	
	printf("enter number of elements you need to print\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int b[n];
	for(i=0;i<n;i++);
	i--;


	for(j=0;i;i--,j++)
	{
		b[j]=a[i];

	}
	b[j]=a[i];


	printf("after in first array....\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nin second array:\n");	

	for(j=0;j<n;j++)
	printf("%d ",b[j]);
	
	printf("\n");

}
