
#include<stdio.h>
#define MAX 3
int queue[MAX];
int front=-1,rear=-1;
void enqueue(void);
int dequeue(void);
int peek(void);
void display(int queue[]);
void enqueue()
{
int num;
if((front == rear+1) || (front == 0 && rear == MAX-1))
{
printf("\n Queue is overflow");
}
else if(front==-1 && rear==-1)
{
printf("\n Enter the number to be inserted in the queue:");
scanf("%d",&num);
front=rear=0;
queue[rear]=num;
}
else if(rear==MAX-1 && front!=0)
{
printf("\n Enter the number to be inserted in the queue:");
scanf("%d",&num);
rear=0;
queue[rear]=num;
}
else
{
printf("\n Enter the number to be inserted in the queue:");
scanf("%d",&num);
rear++;
queue[rear]=num;
}
}
int dequeue()
{
int val;
if(front == -1)
{
printf("\n Queue UNDERFLOW");
}
else
{
val=queue[front];if(front==rear)
{
front=rear=-1;
}
else if(front==MAX-1)
{
front=0;
}
else
{
front++;
}
return val;
}
}
int peek()
{
if(front == -1)
{
printf("\n Queue UNDERFLOW");
}
else
{
return (queue[front]);
}
}
void display(int queue[])
{
int i;
printf("\n");
if(front == -1)
{
printf("\n Queue UNDERFLOW");
}
else
{
if(front != -1 && rear!= -1)
{
if(front<rear)
{
for(i=front;i<=rear;i++)
{
printf("\t %d",queue[i]);
}
}else
{
for(i=front;i<MAX;i++)
printf("\t %d",queue[i]);
for(i=0;i<=rear;i++)
printf("\t%d",queue[i]);
}
}}
}
int main()
{
int val,option;
do
{
printf("\n*****MAIN MENU *****");
printf("\n 1. Insert an element");
printf("\n 2. Delete an element");
printf("\n 3. PEEK");
printf("\n 4. Display");
printf("\n 5. Exit");
printf("\n ********************");
printf("\n \n Enter your choice: ");
scanf("%d",&option);
switch(option)
{
case 1:
enqueue();
break;
case 2:
val=dequeue();
printf("\n the value deleted from the queue is:%d",val);
break;
case 3:
val=peek();
printf("\n the first value in the queue is: %d",val);
break;
case 4:
display(queue);
break;
}}while(option!=5);
return 0;
}