// Merge two Linked List in sorted order

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



struct Node* SortedMerge(struct Node* a, struct Node* b) 
{
  struct Node* result = NULL;
 
  // Base cases 
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  // Pick either a or b and recur
  if (a->data <= b->data) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}


// Driver program to test above functions
void main()
{
    struct Node* result = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;

    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    printf("The first Linked List is: \n");
    printList(a);

    push(&b, 4);
    push(&b, 5);
    push(&b, 6);
    printf("The second Linked List is: \n");
    printList(b);


    result = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(result);
}



