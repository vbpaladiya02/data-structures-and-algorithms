#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node   *new_node,*current,*start;
	int a,n,i;
	
	printf("Enter the size of Linked List: ");
	scanf("%d",&n);
	
	start=NULL;
	for(i=0; i<n; i++)
	{
		printf("Enter the Data: ");
		scanf("%d",&a);
		new_node=malloc(sizeof(struct node));
		new_node->data=a;
		new_node->next=NULL;
	
	
		if(start==NULL)
		{
			start=new_node;
			current=new_node;
		}
		else
		{
			
			current->next=new_node;
			current=new_node;
		}
	}
	//insert a node at start
		struct node *insert;
		int item;
		insert = malloc(sizeof(struct node));
		printf("Enter an item you wish to insert: ");
		scanf("%d",&item);
		insert->data = item;
		insert->next = start;
		start = insert;
		printf("\n Node inserted: ");
	
	//display list
		printf("The Linked List is: \n");
		current=start;
		while(current!=NULL)
		{
			
			printf("%d--->",current->data);
			
			current=current->next;
			
    	}
		printf("NULL");
		
	return 0;
}
