// C program to find the Smallest and the Largest element in a Binary Search Tree


#include<stdio.h>
#include<stdlib.h>
  

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
  


// A utility function to create a new BST node
struct node *newNode(int data)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

  

// A Function to print InOrder traversal of BST
void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("  %d  ", root->data);
        InOrder(root->right);
    }
}
  


// A Function to Insert a new node with given data in BST
struct node* Insert(struct node* root, int data)
{
    // If the tree is empty, return a new node 
    if (root == NULL) return newNode(data);
 
    // Otherwise, recur down the tree 
    if (data < root->data)
        root->left  = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);   
 
    // return the (unchanged) node pointer 
    return root;
}
  


// Compute the height of a Binary Tree -- the number of nodes along the longest path from the root node down to the farthest leaf node
int maxDepth(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       // compute the depth of each subtree
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       // use the larger one
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}



void printGivenLevel(struct node* , int);
// Given a binary tree, print its nodes according to the Level Order Traversal
void printLevelOrder(struct node* root)
{
    int h = maxDepth(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}


 
// Function to print nodes at a given level
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("  %d  ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
} 


// Function to find the Smallest 
struct node* Smallest(struct node* root)
{
    if(root == NULL || root->left == NULL)
      return root;
    else 
      return Smallest(root->left);
}


// Function to find the Largest
struct node* Largest(struct node* root)
{
    if(root == NULL || root->right == NULL)
      return root;
    else 
      return Largest(root->right);
}



/*
// Driver Program to test above functions
void main()
{

    int data,choice,key; 
    
    struct node *root = NULL;
  
    printf("Enter the value to be Inserted \n");
    scanf("%d",&data);
    root = Insert(root, data);

    while(1)
    {
    printf("press 1 to continue Insertion and 2 to exit");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:printf("Enter the value to be Inserted \n");
             scanf("%d",&data);
             Insert(root, data);
             break;

      case 2:// print InOrder traversal of the BST
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
             printf("\nInOrder traversal of the Binary Search Tree is : \n");
             InOrder(root);
             printf("\n");
             printf("\nLevel Order traversal of the Binary Search Tree is : \n");
             printLevelOrder(root);
             
             printf("\nHeight of the BST is :   %d\n\n",maxDepth(root));
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");


		struct node* ptr1;
		struct node* ptr2;
		ptr1=Smallest(root);
		printf("\nSmallest element in the BST is :   %d\n",ptr1->data);
		ptr2=Largest(root);
		printf("\nLargest element in the BST is :   %d\n",ptr2->data);

		printf("\n");



             exit(0);
             break;
 
      default:printf("Error !!! Choose correctly \n");
    }  

    }  


} 
*/





// Driver Program to test above functions
void main()
{ 
    int key;

    struct node *root = NULL;
  
    root = Insert(root, 45);

    
    Insert(root, 39);
    Insert(root, 56);
    Insert(root, 12);
    Insert(root, 34);
    Insert(root, 78);
    Insert(root, 32);
    Insert(root, 10);
    Insert(root, 89);
    Insert(root, 54);
    Insert(root, 67);
    Insert(root, 81);



// print InOrder and Level Order traversal of the BST
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
             printf("\nInOrder traversal of the Binary Search Tree is : \n");
             InOrder(root);
             printf("\n");
             printf("\nLevel Order traversal of the Binary Search Tree is : \n");
             printLevelOrder(root);
             
             printf("\nHeight of the BST is :   %d\n\n",maxDepth(root));
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
             
struct node* ptr1;
struct node* ptr2;
ptr1=Smallest(root);
printf("\nSmallest element in the BST is :   %d\n",ptr1->data);
ptr2=Largest(root);
printf("\nLargest element in the BST is :   %d\n",ptr2->data);

printf("\n");




} 




/*
// Driver Program to test above functions
void main()
{ 
    int key;

    struct node *root = NULL;
  
    root = Insert(root, 39);

    
    Insert(root, 27);
    Insert(root, 45);
    Insert(root, 18);
    Insert(root, 29);
    Insert(root, 40);
    Insert(root, 54);
    Insert(root, 9);
    Insert(root, 21);
    Insert(root, 28);
    Insert(root, 36);
    Insert(root, 59);
    Insert(root, 10);
    Insert(root, 19);
    Insert(root, 65);
    Insert(root, 60);




// print InOrder and Level Order traversal of the BST
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
             printf("\nInOrder traversal of the Binary Search Tree is : \n");
             InOrder(root);
             printf("\n");
             printf("\nLevel Order traversal of the Binary Search Tree is : \n");
             printLevelOrder(root);
             
             printf("\nHeight of the BST is :   %d\n\n",maxDepth(root));
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
             

struct node* ptr1;
struct node* ptr2;
ptr1=Smallest(root);
printf("\nSmallest element in the BST is :   %d\n",ptr1->data);
ptr2=Largest(root);
printf("\nLargest element in the BST is :   %d\n",ptr2->data);

printf("\n");




} 
*/


