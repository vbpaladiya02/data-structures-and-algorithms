//Search an element in Tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *tree=NULL;
struct node *insert(struct node *,int);
int search_element(struct node *,int item,int flag);
void inorder(struct node *);
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
else
nodeptr=nodeptr->right;
}
if(val<parentptr->data)
parentptr->left=ptr;
else
parentptr->right=ptr;
}
return tree;
}
void inorder(struct node *tree){
if(tree!=NULL)
{
inorder(tree->left);
printf("%d\t",tree->data);
inorder(tree->right);
}
}
int search_element(struct node *tree,int item, int flag)
{
if(tree==NULL)
{
return flag;
}
if(item==tree->data)
{
flag=1;
return flag;
}
if(item<tree->data)
{
tree=tree->left;
}
else
{
tree=tree->right;
}
while(tree!=NULL)
{
if(tree->data==item)
{
flag=1;
return flag;
}
else
{
if(item<tree->data)
{
tree=tree->left;
}
else
{
tree=tree->right;
}
}
}
return flag;
}
int main()
{int option,val,flag,item;
struct node *ptr;
do
{
flag=0;
printf("\n************* MAIN MENU ****************\n");
printf("\n1. Insert");
printf("\n2.inorder");
printf("\n3.seach element");
printf("\n4. Exit");
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
inorder(tree);
break;
case 3:
printf("\nEnter the element you want to search: ");
scanf("%d",&item);
flag=search_element(tree,item,flag);
if(flag==0)
{
printf("\n\nElement is not present in the tree !");
}
else
{
printf("\n\nElement is present in the tree !");
}
break;
}
}while(option!=4);
return 0;
}