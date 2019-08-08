#include<stdio.h>
struct p
{
int x;
int y;

};
void tej(struct p *);
int main()
{
struct p q[2]={1,2};
//tej(q);
printf("%d,%d,%d,%d",q[0].x,q[0].y,q[1].x,q[1].y);		
}

void tej(struct p l[])
{
printf("%d\n",l->x);

}
