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
 


// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\n");
}



// Checks whether two given Linked List are identical or not
void areIdentical(struct Node *a, struct Node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
        {
            printf("Not Identical\n");
            return;
        }
    // If we reach here, then a and b are not NULL and their data is same, so move to next nodes in both lists
        a = a->next;
        b = b->next;
    }

   if(a==NULL && b==NULL)
   printf("Identical\n");
   else
   printf("Not Identical\n");
 
}
 


// Driver program to test above functions
void main()
{
    struct Node *a = NULL;
    struct Node *b = NULL;

    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    printf("The first Linked List is: \n");
    printList(a);

    push(&b, 1);
    push(&b, 2);
    push(&b, 3);
    printf("The second Linked List is: \n");
    printList(b);

 
    areIdentical(a, b);
}



