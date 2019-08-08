#include<stdio.h>
int main()
{
	int k=5;
	int *r=&k;
	int **m=&r;
	printf("%d %d %d\n",k,*r,**m);

}
