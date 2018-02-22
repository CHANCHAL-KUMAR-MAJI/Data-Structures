// Push Pop Peep operation using Linked List

       
#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Node *top = NULL;

void push(int);
void pop();
void peep();
void display();

void main()
{
   int choice, value;
   printf("\n:: Stack using Linked List ::\n");
   while(1){
      printf("\n***** MENU *****\n");
      printf("1. Push\n2. Pop\n3. Peep\n4. Exit\n");
      printf(" Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf(" Enter the value to be inserted: ");
		 scanf("%d", &value);
		 push(value);
		 display();
		 break;
	 case 2: pop(); 
		 display();
		 break;
	 case 3: peep(); 
		 display();
		 break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}


void push(int value)
{
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
}


void pop()
{
   if(top == NULL)
      printf("\n Stack is Empty!!! \n");
   else{
      struct Node *temp = top;
      printf("\n Deleted element is : %d ", temp->data);
      top = temp->next;
      free(temp);
   }
}


void peep()
{
   if(top==NULL)
      printf("\nStack is Empty\n");
   else
      printf(" The value at the top of the stack is : %d ",top->data);
}


void display()
{
   if(top == NULL)
      printf("\n Stack is Empty!!! \n");
   else{
	printf(" The resulting stack is : ");
      struct Node *temp = top;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp->next;
      }
      printf("%d--->NULL",temp->data);
   }
} 


