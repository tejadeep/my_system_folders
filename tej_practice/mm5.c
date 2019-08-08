#include<stdio.h>
int main()
{
	int a[3]={1,2,3};
	int *r=a;
	int *p=&r;
	printf("%d",(**p));



}
