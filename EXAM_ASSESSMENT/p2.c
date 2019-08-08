#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	


}node;
void order(node *);
node *root=0;
node *create(int ele)
{
	node *new=(node *)malloc(sizeof(node));
	if(root==0)
	{
	new->data=ele;
	new->left=0;
	new->right=0;
	root=new;	
	}
	
	else
	{
		node *temp=root, *temp1;
		while(temp!=0)
		{
		if(ele>temp->data)
		{
		temp1=temp;
		temp=temp->right;
	
		
		}
		else
		{
		temp1=temp;
		temp=temp->left;
		}
		}
		
		if(ele>temp1->data)
		{
		new->data=ele;
		new->right=0;
		new->left=new;

		}
		else
		{
		new->data=ele;
		new->right=0;
		new->left=0;
		temp1->left=new;
		}



	}
		
		
}	

int main()
{
	int i,n;
	printf("enter the no of elements in tree\n");
	scanf("%d ",&n);
	printf("enter the ele\n");
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	{
	create(a[i]);
	
	printf("\n inorder is ");
	order(root);
	
	
	}



}

void order(node *root)
{
	if(root==0)
	return;
	order(root->left);
	printf("%d ",root->data);
	order(root->right);




}
