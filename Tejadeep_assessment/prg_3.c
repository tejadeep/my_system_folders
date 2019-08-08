#include<stdio.h>
struct tej
{
	int a:4;
	int b:3;
};
int main()
{
	struct tej t={7,2};
	printf("%d   %d\n",t.a,t.b);
}
