#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;

void Enqueue()
{
    struct node *new;
    int dt;
    printf("\n||:::Enter -1 to end:::||\n");
    printf("Enter the queue data::\n");
    scanf("%d",&dt);
    while(dt!=-1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->info=dt;
        new->link=NULL;
        if(front==NULL && rear==NULL)
        {
            front=rear=new;
        }
        else
        {
            rear->link=new;
            rear=new;
        }
        printf("Enter the queue data::\n");
        scanf("%d",&dt);
    }

} 
void display()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->link;
    }
}
void Dequeue()
{
    struct node *temp;
    temp=front;
    front = front->link;
    free(temp);
}
void peek()
{
    printf("\nFront of data in queue:: %d",front->info);

}
int main()
{
int choice;
    printf("1::Enqueue - insert element in queue\n");
    printf("2::dequeue - delete element in queue..\n");
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
                Enqueue();
                printf("\n||::inserted element in queue::||\n");
                break;
            case 2:
                 Dequeue();
                 printf("\n||::deleted element in queue::||\n");
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