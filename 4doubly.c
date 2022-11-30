#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left,*right;
};

struct node *insert(struct node *start,int data)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
t->data=data;
t->left=(struct node *)0;
t->right=start;
if(start!=(struct node *)0)
start->left=t;
start=t;
return start;
}

struct node *search(struct node *dl,int item)
{
while(dl!=(struct node *)0 &&dl->data!=item)
dl=dl->right;
return dl;
}
struct node *delete(struct node *dl,struct node *t)
{
if(t->left==(struct node *)0 && t->right==(struct node *)0)
dl=(struct node *)0;
else if(t->left==(struct node *)0)
{
t->right->left=(struct node *)0;
dl=dl->right;
}
else if(t->right==(struct node *)0)
t->left->right=(struct node *)0;
else
{
t->left->right=t->right;
t->right->left=t->left;
}
free(t);
return dl;
}

void main()
{
struct node *l1=(struct node *)0,*t;
int opt,data;
do
{
printf("\n1.insert\n");
printf("2.search\n");
printf("3.delete\n");
printf("4.exit\n");
printf("option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("enter data:");
        scanf("%d",&data);
        l1=insert(l1,data);
        printf("inserted %d",data);
        break;
case 2:printf("item to search:");
        scanf("%d",&data);
        t=search(l1,data);
        if(t==(struct node *)0)
        printf("not found");
        else
        printf("found");
        break;
case 3:printf("item to delete:");
        scanf("%d",&data);
        t=search(l1,data);
        if(t!=(struct node *)0)
        {
        l1=delete(l1,t);
        printf("deleted %d",data);
        }
        else
        printf("not exist\n");
        break;
case 4:exit(0);
}
}
while(1);
}
