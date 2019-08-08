// capitilse first and last letter of word in a line
/*
#include<stdio.h>
int main()
{
	FILE *fp;
	int flag=1;
	char c;
	fp=fopen("tej","r+");
	while((c=fgetc(fp))!=-1)
	{
	
	if(flag==1)
	{
	c=c-32;
	fseek(fp,-1,SEEK_CUR);
	fputc(c,fp);
	flag=0;
	}
	if(c==' ')
	{
	flag=1;
		

	}
	}
	
return 0;	
}
*/

#include<stdio.h>
int main()
{
	char a[10];
	int i;
	FILE *fp;
	fp=fopen("tej","r+");
	while(fscanf(fp,"%s",a)!=-1)
	{

	for(i=0;a[i];i++);
	if((a[0]>='a' && a[0]<='z' )|| (a[i-1]>='a' && a[i-1]<='z'))
	{
		a[0]=a[0]-32;
		a[i-1]=a[i-1]-32;
	}
	fseek(fp,-i,SEEK_CUR);
	fprintf(fp,"%s",a);
	
	}


}

