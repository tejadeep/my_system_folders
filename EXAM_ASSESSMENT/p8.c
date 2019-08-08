#include<stdio.h>
#include<stdlib.h>
struct vot
{
	int num;
	struct vot *next;
};
typedef struct vot SL;
static int flag;
void add_beg(SL **);
void display(SL *);
int tej_sort(SL *);
void sort(SL *);
void combine(SL *ptr,SL *lpr);
int main()
{
	int n,b;
	SL *hptr=0;
	SL *lptr=0;
	
	char ch;
	printf("*******enter the first linked list******\n");
label:
	hptr=0;
	do
	{
		add_beg(&hptr);
		printf("want more Y/N \n");
		scanf(" %c",&ch);

	}while(ch=='y'||ch=='Y');
	display(hptr);
	if(hptr==0 && lptr==0)
	{
	printf("no nodes are formed\n");
	return 0;
	}
	n=tej_sort(hptr);
	if(n==1)
	{
	printf("your given data of first linked list is 'not' in sorting order\n please give again\n");
	goto label;
	}

	printf("********enter the second linked list*******\n");
	label2:
 lptr=0;
	do
	{
		add_beg(&lptr);
		printf("want more Y/N \n");
		scanf(" %c",&ch);

	}while(ch=='y'||ch=='Y');
	printf("\n");
	display(lptr);
	b=tej_sort(lptr);
	if(b==1)
	{
	printf("your given data of second linked list is 'not' in sorting order\n please give again\n");
	goto label2;
	}
	if(flag!=2 && flag!=0)
	{
	printf("flag=====%d\n",flag);
	printf("both linkedlist must be same\n");
	return 0;
	}
	combine(hptr,lptr);
	sort(hptr);
//	printf("*********output::************\n");
	display(hptr);
	return 0;
}
void add_beg(SL **ptr)
{
	SL *temp;
	temp=(SL *)malloc(sizeof(SL));
	printf("enter the number\n");
	scanf("%d",&temp->num);
	
	temp->next=*ptr;
	*ptr=temp;
	
}
void combine(SL *ptr,SL *lpr)
{
	while(ptr->next)
	{
	ptr=ptr->next;
	}
	ptr->next=lpr;
}

int tej_sort(SL *ptr)
{
	SL *i;
	i=ptr;
	if(i->num > i->next->num)
	{
	flag++;
	while(i->next)
	{
	if(i->num < i->next->num)
	{
	printf("tejjjjjjjjjjjjjjjjj\n");
	return 1;
	}
	
	i=i->next;
	}
//	printf("******* %d *******\n",flag);	
	
	}
	else
	{
	while(i->next)
	{

	if(i->num > i->next->num)
	return 1;
	i=i->next;
	}
	}
	
}

void sort(SL *ptr)
{
	SL *i;
	i=ptr;
	int temp,tej;
	if(i->num<i->next->num)
	{
	printf("ascending orderrrrrr\n");
	do
	{
	tej=0;
	i=ptr;
	while(i->next)
	{
		if(i->num > i->next->num)
		{
		temp=i->num;
		i->num=i->next->num;
		i->next->num=temp;
		tej=1;
		}
	i=i->next;
	}
	}while(tej);
	}
	else
	{
	printf("descending order............\n");
	do
	{
	tej=0;
	i=ptr;
	
	while(i->next)
	{
		if(i->num < i->next->num)
		{
		temp=i->num;
		i->num=i->next->num;
		i->next->num=temp;
		tej=1;
		}
	i=i->next;
	}
	}while(tej);
	}

printf("done\n");
}	
	

void display(SL *p)
{
	while(p)
	{
	printf("%d ",p->num);
	p=p->next;
	}
	printf("\n");
}



