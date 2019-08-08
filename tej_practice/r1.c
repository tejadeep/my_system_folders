#include<stdio.h>
typedef struct
{
	int a;
	int b;
	int c;

}tej;

void hi(volatile tej *r,int a,int b)
{
	while(r->c)
	{
		printf("hello");
	}
	
	r->a=a;
	r->b=b;

}
int main()
{
tej hptr;
hi(&hptr,1,2);
}
