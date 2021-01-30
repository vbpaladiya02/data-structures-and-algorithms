#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *start=NULL;
void create()
{
    struct node *new,*temp;
    int dt;
    printf("\n||:::Enter -1 to end:::||\n");
    printf("Enter the data of newnode::\n");
    scanf("%d",&dt);
    while(dt!=-1)
    {
        new=(struct node *)malloc(sizeof(struct node));
        new->info=dt;
        new->link=NULL;
        if(start == NULL)
            start=temp=new;    
        else
        {
            temp->link=new;
            temp=new;
        }
        printf("\n||:::Enter -1 to end:::||\n");
        printf("Enter the data of newnode::\n");
        scanf("%d",&dt);
    } 
}
void display()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d->",temp->info);
        temp=temp->link;
    }
    printf("NULL");
    
}
void instBeg()
{
    struct node *new;
    int dt;
    printf("enter the data of new node::\n");
    scanf("%d",&dt);
    new = (struct node *)malloc(sizeof(struct node));
    new->info=dt;
    new->link=NULL;
    new->link=start;
    start=new;
}
void instMid()
{
    struct node *new,*temp ;
    int dt,pos,i=1;
    printf("enter the postion where you want to  enter::\n");
    scanf("%d",&pos);
    printf("enter the data of newnode::\n");
    scanf("%d",&dt);
    new = (struct node *)malloc(sizeof(struct node));
    new->info=dt;
    new->link=NULL;
    temp=start;
    while(i<pos-1)
    {
        temp=temp->link;
        i++;
    }
    new->link=temp->link;
    temp->link=new;
}
void instEnd()
{
    struct node *new,*temp;
    int dt;
    printf("enter the data of newnode::\n");
    scanf("%d",&dt);
    new = (struct node *)malloc(sizeof(struct node));
    new->info=dt;
    new->link=NULL;
    temp=start;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new;
}
void deltBeg()
{
    struct node *temp;
    temp=start;
    start=start->link;
    free(temp);
}
void deltMid()
{
    struct node *temp,*ptr;
    int pos,i=1;
    printf("enter the position that where you want to delete::\n");
    scanf("%d",&pos);
    temp=start;
    while(i<=pos-1)
    {
        
        ptr=temp;
        temp=temp->link;
        i++;
    }
    ptr->link=temp->link;
    free(temp);
}
void deltEnd()
{
    struct node *temp,*ptr;
    temp=start;
    while(temp->link!=NULL)
    {
         ptr=temp;
        temp=temp->link;
    }
     ptr->link=NULL;
    free(temp);
}
int main()
{
    int choice;
    printf("\n1::create list..\n");
    printf("2::display list..\n");
    printf("3::insert beginng..\n");
    printf("4::insert your entered postion..\n");
    printf("5::insert ending..\n");
    printf("6::delete begining..\n");
    printf("7::delete your entered postion..\n");
    printf("8::delete ending..\n");
    printf("9::Exit..\n");
    while(choice!=9)
    {
        printf("\nEnter the your choice::\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                instBeg();
                printf("||::Node is inserted at begining::||\n");
                break;
            case 4:
                instMid();
                printf("||::Node is inserted at middle::||\n");
                break;
            case 5:
                instEnd();
                printf("||::Node is inserted in ending::||\n");
                break;
            case 6:
                deltBeg();
                printf("||::Node is deleted at begining::||\n");
                break;
            case 7:
                deltMid();
                printf("||::Node is delete at middle:::||\n");
                break;
            case 8:
                deltEnd();
                printf("||::Node is delete at ending::||\n");
                break;
        }
    }
}
