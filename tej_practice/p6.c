//basic program on binary search tree

#include<stdio.h>
#include<stdlib.h>
struct tej
{
	int num;
	struct tej *left;
	struct tej *right;

};
typedef struct tej SL;
SL* add()
{
	SL *temp;
	temp=(SL *)malloc(sizeof(SL));
	printf("eenter the number......\n");
	scanf("%d",&temp->num);
	
	temp->left=0;
	temp->right=0;
	
	
}
void display(SL *ptr)
{
if(ptr!=0)
{
display(ptr->left);
	printf("%d ",ptr->num);

display(ptr->right);
}

}


int main()
{
	SL *root=add();
	root->left=add();
	root->right=add();
	root->left->left=add();
	display(root);
	return 0;

}

