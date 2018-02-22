// Function to print Level Order Traversal of a Binary Tree


#include <stdio.h>
#include <stdlib.h>

 
// A binary tree node has data, pointer to left child and a pointer to right child
struct node
{
     char data;
     struct node* left;
     struct node* right;
};



// Helper function that allocates a new node with the given data and NULL left and right pointers
struct node* newNode(char data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}



// Given a binary tree, print its nodes according to the PreOrder traversal
void printPreOrder(struct node* node)
{
     if (node == NULL)
          return;
 
     // first print the data of node
     printf("  %c  ", node->data);  
 
     // then recur on left sutree
     printPreOrder(node->left);  
 
     // then recur on right subtree
     printPreOrder(node->right);
} 



// Given a binary tree, print its nodes according to the InOrder traversal
void printInOrder(struct node* node)
{
     if (node == NULL)
          return;
 
     // first recur on left subtree
     printInOrder(node->left);
 
     // then print the data of node
     printf("  %c  ", node->data);  
 
     // then recur on right subtree
     printInOrder(node->right);
}



// Given a binary tree, print its nodes according to the PostOrder traversal
void printPostOrder(struct node* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostOrder(node->left);
 
     // then recur on right subtree
     printPostOrder(node->right);
 
     // then print the data of node
     printf("  %c  ", node->data);
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
        printf("  %c  ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}




// Driver program to test the above functions
void main()
{
     struct node *root  = newNode('F');


	root->left             = newNode('D');
	root->left->left     = newNode('B');
	root->left->right     = newNode('E');
	root->left->left->left     = newNode('A');
	root->left->left->right     = newNode('C');
	root->right           = newNode('J');
	root->right->left     = newNode('G');
	root->right->right     = newNode('K');
	root->right->left->right     = newNode('I');
	root->right->left->right->left     = newNode('H');
    
     
printf("\n---------------------------------------------------------------------------------------------------------------------\n");
 
     printf("\nPreOrder traversal of binary tree is : \n");
     printPreOrder(root);
 
     printf("\nInorder traversal of binary tree is : \n");
     printInOrder(root);  
 
     printf("\nPostorder traversal of binary tree is : \n");
     printPostOrder(root);

     printf("\nLevel Order traversal of binary tree is : \n");
     printLevelOrder(root);

printf("\n\n---------------------------------------------------------------------------------------------------------------------\n");

printf("\n");

}




/*
// Driver program to test the above functions
void main()
{
     struct node *root  = newNode('A');


	root->left             = newNode('B');
	root->left->left     = newNode('D');
	root->left->right     = newNode('E');
	root->left->left->left     = newNode('G');
	root->left->left->right     = newNode('H');
	root->left->left->right->right     = newNode('L');
	root->right           = newNode('C');
	root->right->right     = newNode('F');
	root->right->right->left     = newNode('I');
	root->right->right->right     = newNode('J');
	root->right->right->right->left     = newNode('K');
    
     
printf("\n---------------------------------------------------------------------------------------------------------------------\n");
 
     printf("\nPreOrder traversal of binary tree is : \n");
     printPreOrder(root);
 
     printf("\nInorder traversal of binary tree is : \n");
     printInOrder(root);  
 
     printf("\nPostorder traversal of binary tree is : \n");
     printPostOrder(root);

     printf("\nLevel Order traversal of binary tree is : \n");
     printLevelOrder(root);

printf("\n\n---------------------------------------------------------------------------------------------------------------------\n");

printf("\n");

}
*/



/*
// Driver program to test the above functions
void main()
{
     struct node *root  = newNode('A');


	root->left             = newNode('B');
	root->left->right     = newNode('D');

	root->right           = newNode('C');
	root->right->left     = newNode('E'); 
	root->right->left->right     = newNode('F');
	root->right->left->right->left     = newNode('G');
	root->right->left->right->left->left     = newNode('H');
	root->right->left->right->left->right     = newNode('I');
    
     
printf("\n---------------------------------------------------------------------------------------------------------------------\n");
 
     printf("\nPreOrder traversal of binary tree is : \n");
     printPreOrder(root);
 
     printf("\nInorder traversal of binary tree is : \n");
     printInOrder(root);  
 
     printf("\nPostorder traversal of binary tree is : \n");
     printPostOrder(root);

     printf("\nLevel Order traversal of binary tree is : \n");
     printLevelOrder(root);

printf("\n\n---------------------------------------------------------------------------------------------------------------------\n");

printf("\n");

}
*/




