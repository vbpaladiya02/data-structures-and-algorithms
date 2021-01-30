#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf(" ||::Enter -1 to end::||\n");
    printf("\n Enter the data:");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node *));
        new_node->data = num;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = start;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            new_node->next = start;
            ptr->next = new_node;
        }
        printf("\n Enter the data:");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("\n");
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr->next != start)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
        //ptr= ptr->next;
        printf("\t %d", ptr->data);
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = num;
    new_node->next = start;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}
struct node *insert_mid(struct node *start)
{
    struct node *new,*temp ;
    int dt,pos,i=1;
    printf("enter the postion where you want to  enter::\n");
    scanf("%d",&pos);
    printf("enter the data of newnode::\n");
    scanf("%d",&dt);
    new = (struct node *)malloc(sizeof(struct node));
    new->data=dt;
    new->next=NULL;
    temp=start;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    temp->next=new;
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = start;
    free(ptr);
    return start;
}
struct node *delete_mid(struct node *start)
{

    struct node *temp,*ptr;
    int pos,i=1;
    printf("Enter the position that where you want to delete::\n");
    scanf("%d",&pos);
    temp=start;
    while(i<=pos-1)
    {
        
        ptr=temp;
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    free(temp);
    return start;
}
int main()
{
    int option;
    do
    {
        printf("\n\n ***MAIN MENU***");
        printf("\n 1:create a list");
        printf("\n 2: Display list");
        printf("\n 3:Add a node in the beginning");
        printf("\n 4:Add a node at the end");
        printf("\n 5:Inserted from your enter position");
        printf("\n 6:Delete node from the beginning");
        printf("\n 7:Delete node from the end");
        printf("\n 8:Deleted from your enter position");
        printf("\n 9:Exit");
        printf("\n*********************");
        printf("\n \n Enter your choice:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("||::\n LINKED LIST CREATED::||");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            printf("||::INSERTED AT BEGINING::||");
            break;
        case 4:
            start = insert_end(start);
            printf("||::INSERTED AT ENDING::||");
            break;
        case 5:
            start = insert_mid(start);
            printf("||::INSERTED AT MIDDLE::||");
            break;
        case 6:
            start = delete_beg(start);
            printf("||::DELETED AT BEGINING::||");
            break;
        case 7:
            start = delete_end(start);
            printf("||::DELETED AT ENDING::||");
            break;
        case 8:
            start = delete_mid(start);
            printf("||::DELETED AT MIDDLE::||");
            break;
        }
    } while (option != 9);
    return 0;
}