#include<stdio.h>
main()
{
int i;
char a[10]={1,2,3,4,1,2,3,4,5,2};
static char b[10];
for(i=0;i<10;i++)
b[a[i]-1]++;
for(i=0;b[i];i++)
printf("%d ",b[i]);


}
