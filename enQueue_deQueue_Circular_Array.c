// enQueue and deQueue operations on an Circular Array based implementation of a Queue

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void enQueue(int);
void deQueue();
void display();

int queue[SIZE], front = -1, rear = -1;

void main()
{
   int value, choice;
   while(1){
      printf("\n***** MENU *****\n");
      printf("1. enQueue \n2. deQueue \n3. Exit ");
      printf("\n Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf(" Enter the value to be inserted into the Queue : ");
		 scanf("%d",&value);
		 enQueue(value);
		 display();
		 break;
	 case 2: deQueue();
		 display();
		 break;
	 case 3: exit(0);
	 default: printf("\n Wrong selection!!! Try again!!!");
      }
   }
}



// Function to perform enQueue
void enQueue(int value){
   if(((rear+1)%SIZE)==front)
      printf("\nOVERFLOW !!! Queue is Full!!! Insertion is not possible!!!");
   else if (front==-1 && rear==-1)
      {
      front=rear=0;
      queue[rear]=value;
      }
   else
      {
      rear=(rear+1)%SIZE;
      queue[rear]=value;
      }
}



// Function to perform deQueue
void deQueue(){
   if(front==-1 && rear==-1)
      printf("\nUNDERfLOW !!! Queue is Empty!!! Deletion is not possible!!!");
   else if (front==rear)
      front=rear=-1;
   else 
      front=(front+1)%SIZE;
}



// Function to display the resulting Queue
void display(){
   int i;
   if(front==-1 && rear==-1)
      printf("\n Queue is Empty!!! ");
   else 
      { 
	printf("\nThe resulting Queue is : ");
        i=front;
        while(i!=rear){
           i=(i+1)%SIZE;
           printf(" %d ",queue[i]);
      }
      }
}






