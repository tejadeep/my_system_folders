#include<stdio.h>
#include<stdlib.h>
int main()
{
int **p,i,j;
p=malloc(6*sizeof(int *));
for(i=0;i<6;i++)
p[i]=malloc(3*sizeof(int));

for(i=0;i<6;i++)
for(j=0;j<3;j++)
p[i][j]=1;


for(i=0;i<6;i++)
{
for(j=0;j<3;j++)
printf("%d ",p[i][j]);
printf("\n");
}
return 0;
}
