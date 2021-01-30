//PREORDER
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insert(struct node *,int);
void preorder(struct node *);
void create_tree(struct node *tree)
{
tree=NULL;
}
struct node *insert(struct node *tree,int val)
{
struct node *ptr,*nodeptr,*parentptr;
ptr=(struct node*)malloc(sizeof(struct node*));
ptr->data=val;
ptr->left=NULL;
ptr->right=NULL;
if(tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else
{
parentptr=NULL;
nodeptr=tree;
while(nodeptr!=NULL)
{
parentptr=nodeptr;
if(val<nodeptr->data)
nodeptr=nodeptr->left;
elsenodeptr=nodeptr->right;
}
if(val<parentptr->data)
parentptr->left=ptr;
else
parentptr->right=ptr;
}
return tree;
}
void preorder(struct node *tree)
{
if(tree!=NULL)
{
printf("%d\t",tree->data);
preorder(tree->left);
preorder(tree->right);
}
}
int main()
{
int option,val;
struct node *ptr;
create_tree(tree);
do
{
printf("\n************* MAIN MENU ****************\n");
printf("\n1. Insert");
printf("\n2. Preorder");
printf("\n3. Exit");
printf("\n\n***************************************");
printf("\n\nEnter your option:");
scanf("%d",&option);
switch(option)
{
case 1:
printf("\n enter value:");
scanf("%d",&val);
tree=insert(tree,val);
break;
case 2:
printf("\n the elements of the tree are:\n");
preorder(tree);break;
}
}while(option!=3);
return 0;
}