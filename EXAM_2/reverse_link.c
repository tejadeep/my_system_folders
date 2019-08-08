#include<stdio.h>
#include<stdlib.h>
struct vot
{
	int num;
	struct vot *next;
};
typedef struct vot SL;
void add_beg(SL **);
void display(SL *);
void reverse(SL **);
int main()
{
	int n,b;
	SL *hptr=0;
	
	char ch;
	hptr=0;
	do
	{
		add_beg(&hptr);
		printf("want more Y/N \n");
		scanf(" %c",&ch);

	}while(ch=='y'||ch=='Y');
	display(hptr);
	reverse(&hptr);
	display(hptr);
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

void reverse(SL **ptr)
{
	SL *prev=0;
	SL *current=*ptr;
	SL *next=0;
	
	while(current!=0)
	{
	next=current->next;
	current->next=prev;
	prev=current;
	current=next;
	
	
	}

	*ptr=prev;
	
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



