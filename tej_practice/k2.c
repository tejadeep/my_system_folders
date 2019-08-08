#include<stdio.h>
#include<string.h>
void rev(char *p)
{
int i,j;
char temp;
j=strlen(p);
j--;
for(i=0;i<j;i++,j--)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}

}
int main()
{
	char a[100]="hi hello how are you";
	printf("before::: %s\n",a);
	rev(a);
	printf("after::: %s\n",a);

}
