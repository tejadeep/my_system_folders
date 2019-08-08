//print your name with out using any loop or goto statement

#include<stdio.h>
int main()
{
	static int i=1;
	printf("%d) tejadeeep\n",i);
	i++;
	if(i<=10)
	
	main();
	return 0;
}
