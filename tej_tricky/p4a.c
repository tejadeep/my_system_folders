// capitilse first and last letter of word in a line

#include<stdio.h>
int main()
{
	FILE *fp;
	char s[20];
	int i,j;
	fp=fopen("tej","r+");
	while(fscanf(fp,"%s",s)!=-1)
	{
	printf("%s ",s);
	for(j=0;s[j];j++);
	printf("%d\n",j);
	s[0]=s[0]-32;
	s[j-1]=s[j-1]-32;
	fseek(fp,-j,SEEK_CUR);
	fprintf(fp,"%s",s);
	}
return 0;	
}
