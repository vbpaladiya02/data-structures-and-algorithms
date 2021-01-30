#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *start=NULL;
void create()
{
    struct node *new,*temp;
    int dt;
    printf("\n||:::enter -1 to end:::||\n");
    printf("\nEnter the data of newnode::\n");
    scanf("%d",&dt);
    while(dt!=-1)
    {
        new=(struct node *)malloc(sizeof(struct node));
        new->info=dt;
        if(start==NULL)
        {
            start=temp=new;
            new->next=NULL;
            new->prev=NULL;
        }
        else
        {
            new->prev=temp;
            temp->next=new;
            temp=new;
            new->next=NULL;

        }
        printf("\n||:::enter -1 to end:::||\n");
        printf("\nEnter the data of newnode::\n");
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
        temp=temp->next;
    }    
    printf("NULL");
}
void instBeg()
{
    struct node *new;
    int dt;
    printf("\nEnter the data of newnode::\n");
    scanf("%d",&dt);
    new=(struct node *)malloc(sizeof(struct node));
    new->info=dt;
    new->next=start;
    start=new;
    new->prev=NULL;   
}
void instMid()
{
    struct node *new,*temp;
    int dt,pos,i=1;
    printf("\nEnter the postion that where you want to  enter::\n");
    scanf("%d",&pos);
     printf("Enter the data of newnode::\n");
     scanf("%d",&dt);
     new=(struct node *)malloc(sizeof(struct node));
     new->info=dt;
     temp=start;
     while(i<pos-1)
     {
         temp=temp->next;
         i++;
     }
    new->prev=temp;
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;   
}
void instEnd()
{
    struct node *temp,*new;
    int dt;
    printf("\nEnter the data of newnode::\n");
    scanf("%d",&dt);
    new=(struct node *)malloc(sizeof(struct node));
    new->info=dt;
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
    new->next=NULL;
}
void deltBeg()
{
    struct node *temp;
    temp=start;
    start=temp->next;
    temp->next->prev=NULL;
    free(temp);
}
void deltMid()
{
    struct node *temp,*ptr;
    int pos,i=1;
    printf("Enter the postion that where you want to delete::\n");
    scanf("%d",&pos);

    temp=start;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    ptr=temp->next;
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    free(ptr);

}
void deltEnd()
{
    struct node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
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
        printf("\nEnter the your choice...\n");
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
                printf("\n||::Node is inserted at begining::||\n");
                break;
            case 4:
                instMid();
                printf("\n||::Node is inserted at middle::||\n");
                break;
            case 5:
                instEnd();
                printf("\n||::Node is inserted at ending::||\n");
                break;
            case 6:
                deltBeg();
                printf("\n||::Node is deleted at begining::||\n");
                break;
            case 7:
                deltMid();
                printf("\n||::Node is deleted at middle::||\n");
                break;
            case 8:
                deltEnd();
                printf("\n||::Node is deleted at ending::||\n");
                break;
            
        }
    }
}