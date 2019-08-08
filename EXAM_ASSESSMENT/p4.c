//program to store little enedian n big enedian


#include<stdio.h>
union tej
{
	int num;
	char ch;

}t;
int main()
{
printf("enter the number\n");
scanf("%d",&t.num);
printf("before%d\n",t.num);

printf("now enter the character\n");
scanf(" %c",&t.ch);

printf("this integer value %d ",t.num);

printf("when ever u enter the char it affect little endian byte ...so this is an little endian\n");
}
