#include<stdio.h>
#include<string.h>
void kit(char *a,char *b)
{
	int m=strlen(a);
	int n=strlen(b);
	int i;
	for(i=0;i<=n;i++)
	a[m+i]=b[i];
}

int main()
{
	char *str1="teja";
	char *str2="deep";
	kit(str1,str2);
	printf("%s    %s\n",str1,str2);
}
