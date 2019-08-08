#include<stdio.h>
int main()
{
	char a[20];
	FILE *fd;
	fd=fopen("text","r");
	read(fd,a,10);

	printf("%s ***************",a);
//while(1)
printf(".");	
	
	
	
	
}
