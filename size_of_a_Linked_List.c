// Creating a Linked List
// A complete working C program to demonstrate all insertion methods on Linked List


#include <stdio.h>
#include <stdlib.h>
 

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};
 
   // Start with the empty list 
   struct Node* head = NULL;




// Given a reference (pointer to pointer) to the head of a list and an int data, inserts a new node on the front of the list. 
void push(struct Node** head_ref, int new_data)
{
    // Allocate a new node in memory
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    // Put in the data
    new_node->data  = new_data;
 
    // Make next of new node as head 
    new_node->next = (*head_ref);
 
    // Move the head to point to the new node 
    (*head_ref)    = new_node;
}
 


// Given a node prev_node, insert a new node after the given prev_node
void insertAfter(struct Node* prev_node, int new_data)
{
    // Check if the given prev_node is NULL
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
 
    // Allocate a new node in memory
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    // Put in the data
    new_node->data  = new_data;
 
    // Make next of new node as next of prev_node
    new_node->next = prev_node->next;
 
    // Move the next of prev_node as new_node
    prev_node->next = new_node;
}
 


// Given a reference (pointer to pointer) to the head of a list and an int data, appends a new node at the end
void append(struct Node** head_ref, int new_data)
{
    // Allocate a new node in memory
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    // Put in the data
    new_node->data  = new_data;
 
    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
 
    // If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
 
    // Else traverse till the last node
    struct Node *last = *head_ref;    // Used to traverse the linked list 
    while (last->next != NULL)
        last = last->next;
 
    // Change the next of last node to the address of the new node
    last->next = new_node;
    return;
}
 


// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  int c=0;
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
     c++;
  }
  printf("\n");
  printf("The size of the Linked List is %d",c);
  printf("\n");
}
 


// Driver program to test above functions
void main()
{
 
  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);
 
  printf("\n Final Created Linked list is: \n");
  printList(head);
 
}



/* Driver program to test above functions
void main()
{

   
   int k,data;
   char ch;


printf("choose h for inserting at front , l for inserting at last , m for any position inbetween after a given node and q to quit\n");
   
while(1)
{

   scanf("%c",&ch);
   
   
   if(ch=='h')
   {
   printf("Enter the value of Data\n");
   scanf("%d",&data);
   push(&head,data);
   printList(head);
   }

   if(ch=='m')
   {
   printf("Enter the value of Data\n");
   scanf("%d",&data);
   printf("Enter the value after which the new data is to be inserted\n");
   scanf("%d",&k);

    // Else traverse till the required node
    struct Node *last = head;    // Used to traverse the linked list 
    while (last->data != k)
        last = last->next;



   insertAfter(last,data);
   printList(head);
   }
      
   if(ch=='l')
   {
   printf("Enter the value of Data\n");
   scanf("%d",&data);
   append(&head,data);
   printList(head);
   }
   
   if(ch=='q')
   break;
  
}
  






 
  printf("\n Final Created Linked list is: \n");
  printList(head);
 

}

*/

