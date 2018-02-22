// Push Pop Peep operations on a stack using ARRAY


#include<stdio.h>

#define SIZE 5

int top = -1;
int stack[SIZE];

//Function prototypes
void push(int item);
int pop();
int peep();
void display();

void main()
{
	int item, choice, cont = 1;

	while(cont == 1)
	{
		printf("\n1.Push onto stack.\n");
		printf("\n2.Pop from stack.\n");
		printf("\n3.Peep into stack.\n");

		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the value of item: ");
				scanf("%d",&item);
				push(item);
				display();
				break;

			case 2:
				item = pop();
				if(item != NULL)
				{
					printf("\nItem popped out is: %d\n",item);
				}
				display();				
				break;

			case 3:
				item = peep();
				if(item != NULL)
				{
					printf("\nItem at top of stack is: %d\n",item);
				}
				display();				
				break;

			default:
				printf("\nInvalid choice.\n");
				break;
		}

		printf("\nTo continue press 1 otherwise 0 ");
		scanf("%d",&cont);
	}


}

//Function for push operation
void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow. Push not possible.\n");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
	return;
}

//Function for pop operation
int pop()
{
	int item = NULL;

	if(top <= -1)
	{
		printf("\nStack Underflow. Pop not possible.\n");
	}
	else
	{
		item = stack[top];
		stack[top] = NULL;
		top = top-1;
	}
	return(item);
}

//Function for peep operation
int peep()
{
	int item = NULL;

	if(top <= -1)
	{
		printf("\nStack Underflow. No element in stack.\n");
	}
	else
	{
		item = stack[top];
	}
	return(item);
}
void display()
{
	
	if(top>=0 && top<SIZE)
	{
	printf(" Resulting Stack is : ");
	for(int i=0;i<=top;i++)
		printf(" %d ",stack[i]);
	}
}
