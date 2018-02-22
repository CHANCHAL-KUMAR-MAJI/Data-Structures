// C program for different tree traversals - PreOrder - Inorder - PostOrder


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

printf("\n\n---------------------------------------------------------------------------------------------------------------------\n");

printf("\n");

}




