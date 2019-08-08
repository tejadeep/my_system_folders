#include<stdio.h>
main()
{
	int a[]={1,2,3};
	int *p=a;
	int **q=&p;
	printf("%p,%p",*q,a);
}
