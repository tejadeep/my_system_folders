#include<stdio.h>
#include<stdlib.h>
int main()
{
  char str[40]="44 this is test";
  char *ptr;
  long ret;
  ret=strtol(str,&ptr,10);
  printf("strtol retun value issss %d\n",ret);

  printf("***** %s *******\n",str);
  printf("***** %s *******\n",ptr);
  return 0;

}
