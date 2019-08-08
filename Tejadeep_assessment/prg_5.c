#include<stdio.h>
int main()
{
	int a=5;
	int b,c;
	b=++a;   //here 'a' is pre-increment so a=6 and then assign to b so b=6
	c=b++;	//here 'b' is post-increment so first assigned then increment so c=6and b=7
	a=++b+c++; // here b is pre-increment and c is post-increment so b=8 and c=6 and a=8+6=14 after c becomes 7 
	printf("a=%d  b=%d  c= %d\n",a,b,c); // o/p is 14 , 8, 7
}
