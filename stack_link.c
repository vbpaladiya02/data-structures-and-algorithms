#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *top;
void push()
{
    struct node *new;
    int dt;
    printf("\n||:::Enter the -1 to end:::||\n");
    printf("\nEnter the data of stack::\n");
    scanf("%d",&dt);
    while(dt!=-1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->info=dt;
        new->link=NULL;
        if(top==NULL)
            top=new;
        else
        {
            new->link=top;
            top=new;
        }
        printf("\nEnter the data of stack::\n");
        scanf("%d",&dt);
    }
}
void display()
{
    struct node *temp;
    temp=top;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->link;
    }
}
void pop()
{
    struct node *temp;
    temp=top;
    top=top->link;
    free(temp);
}
void peek()
{
    printf("Top element of is :: %d",top->info);
}
int main()
{
int choice;
    printf("1::push - insert element in stack..\n");
    printf("2::pop - delete element in stack..\n");
    printf("3::peek - get the top element..\n");
    printf("4::display - display stack..\n");
    printf("5::Exit..\n");
    while(choice!=5)
    {
        printf("\nEnter the your choice::\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                printf("||::inserted in stack::||");
                break;
            case 2:
                 pop();
                 printf("||::deleted in stack::||");
                 break;
            case 3:
                 peek();
                 break;
            case 4:
                display();
                break;

        }
    }

}