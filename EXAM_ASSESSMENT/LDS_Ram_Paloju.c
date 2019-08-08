#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *arr1,n,i;//[5]={1,2,3,4,5};
  printf("How many elements you want to put in an Array:");
  scanf("%d",&n);
  arr1=(int*)malloc(n*sizeof(int));

  printf("Enter the Array elements :");

  for(i=0;i<n;i++)
  {
   scanf("%d",&arr1[i]);
  }

  printf("You Entered Array is:");
  for(i=0;i<n;i++)
  {
   printf("%d ",arr1[i]);
  }
  printf("\n");
 
  //main program logic is here
int count,j=0,k=0,m=0,l=0;
  for(i=0;;i++)
  {
    count=1;
  label:
    while(arr1[i]>arr1[i+1] && i<(n-1))
    {
     count++;
     i++;
     printf("count=%d i=%d\n",count,i);
    }
    
    if(count>k){
    printf("Times\n");
    k=count; }

    if(m==1)
    break;

    if(i==(n-1))
    { 
     l=0; m++;
     //count=1;
     printf("Main Logic\n");
     if(arr1[i]>arr1[l])
     {
      count++;
      i=l;
     //printf("Inner While loop\n");
      goto label;
      printf("After Goto statement\n");
     }
    
    }
  }
 printf("LDS is %d\n",k);
}
