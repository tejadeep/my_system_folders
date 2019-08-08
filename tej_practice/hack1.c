#include <string.h>
#include<stdio.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
     char *str[10]={"  ","one","two","three","four","five","six","seven","eight","nine"};
     int a, b,i;

     scanf("%d\n%d", &a, &b);
     for(i=a;i<=b;i++)
     {
       if(i>=1 && i<=9)
          printf("%s\n",str[i]);
                                     
     }
        for(i=a;i<=b;i++)
        {
             if(i>=1 && i<=9)
             {
                if(i%2==0)
                printf("even\n");
                else
                printf("odd\n");
             }   
         }
}        
