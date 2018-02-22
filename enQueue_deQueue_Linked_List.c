// enQueue and deQueue operation on a stack using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Node *front = NULL , *rear = NULL;

void enQueue(int);
void deQueue();
void display();



void main()
{
   int choice, value;
   printf("\n:: Queue Implementation using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be inserted : ");
		 scanf("%d", &value);
		 enQueue(value);
                 display();
		 break;
	 case 2: deQueue();
                 display();
                 break;
	 case 3: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}



// Function to perform enQueue operation
void enQueue(int value)
{
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL  &&  rear== NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
}



// Function to perform deQueue operation
void deQueue()
{
   if(front == NULL && rear == NULL)
      printf("\nQueue is Empty!!!\n");
   else if (front==rear)
      front=rear=NULL;
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element is : %d\n", temp->data);
      free(temp);
   }
}



// Function to display the resulting Queue
void display()
{
   if(front == NULL && rear==NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      printf("The resulting Queue is : ");
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf(" %d ",temp->data);
	 temp = temp -> next;
      }
      printf(" %d \n",temp->data);
   }
}  



  
