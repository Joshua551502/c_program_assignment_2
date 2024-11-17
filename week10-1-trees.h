#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0



/* TreeNode structure definition */
struct treeNode{
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};
 // pointer to left subtree
 // node data
 // pointer to right subtree
/* end struct TreeNode */

/* Create Aliases for the TreeNode */
typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePtr;

/* function prototypes */
void insertNode(TreeNodePtr *treePtr, int value);
void insertNodeWithDuplicates(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void reverseOrder(TreeNodePtr treePtr);
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int key);
void deleteNode( TreeNodePtr *treePtr, int value );
void searchNode ( TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found );


/*********Function Definitions**********/
   
/* insert a node into the tree */
void insertNode(TreeNodePtr *treePtr, int value)
{ 

   /* if you are at a leaf-node */
   if(*treePtr == NULL){
      
      /* dynamically allocate memory */
      *treePtr = malloc(sizeof(TreeNode));

      if ( *treePtr != NULL/* if memory was allocated, insert node */ ) { 
         // add code to insert data into node
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      } 
      else {
         //
         puts("Not inserted. No memory available ");
      } 
      return;
   }
   /*otherwise if treePtr is-not NULL, recursively call insertNode */
   else{
      if (value < (*treePtr)->data) {
         // add code here to go left
         insertNode(&((*treePtr)->leftPtr), value);
      } 
      else if (value > (*treePtr)->data){             
         // add code here to go right
         insertNode(&((*treePtr)->rightPtr), value);
      } 
      else { // duplicate value
        // Do-not-insert-duplicate"); 
        printf("Do-not-insert-duplicate ");
      }   
   }
} 

/* traverse the tree inorder */
   /* traverse left subtree, print node, traverse right subtree */
void inOrder(TreeNodePtr treePtr)
{ 
   if(treePtr != NULL){
      inOrder(treePtr->leftPtr);
      printf("%d ", treePtr->data);
      inOrder(treePtr->rightPtr);

   }
} 

/* traverse the tree preorder */
   /* print node, traverse left subtree, traverse right subtree */
void preOrder(TreeNodePtr treePtr)
{ 
   if(treePtr != NULL){
      
      printf("%d ", treePtr->data);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);

   }
} 

/* traverse the tree postorder */
/* traverse left subtree, traverse right subtree, print node */
void postOrder(TreeNodePtr treePtr)
{ 
 if(treePtr != NULL){
      
     
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
      printf("%d ", treePtr->data);

   }
} 

void insertNodeWithDuplicates(TreeNodePtr *treePtr, int value){
 /* if you are at a leaf-node */
   if(*treePtr == NULL){
      
      /* dynamically allocate memory */
      *treePtr = malloc(sizeof(TreeNode));

      if ( *treePtr != NULL/* if memory was allocated, insert node */ ) { 
         // add code to insert data into node
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      } 
      else {
         //
         puts("Not inserted. No memory available ");
      } 
      return;
   }
   /*otherwise if treePtr is-not NULL, recursively call insertNode */
   else{
      if (value <= (*treePtr)->data) {
         // add code here to go left
         insertNodeWithDuplicates(&((*treePtr)->leftPtr), value);
      } 
      else {             
         // add code here to go right
         insertNodeWithDuplicates(&((*treePtr)->rightPtr), value);
      } 
       
   }

}

TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int key)
{
  if (treePtr == NULL )
    {
      // add code here to process search key not found
      return NULL;
           
    }				
  else if (key == treePtr->data)
    {
      // add code here to process search key found
      return treePtr;
            
    }				
  else if (key < treePtr->data)
    {
      // add code here to continue searching left subtree
      binaryTreeSearch(treePtr->leftPtr, key);
             
    }				
  else   /* implies (key > treePtr->data) */
    {
      // add code here to search right tree
      binaryTreeSearch(treePtr->rightPtr, key);
             
    }				
}				



void reverseOrder(TreeNodePtr treePtr){
   if(treePtr != NULL){
      reverseOrder(treePtr->rightPtr);
      printf("%d ", treePtr->data);
      reverseOrder(treePtr->leftPtr);

   }
}

void deleteNode ( TreeNodePtr *treePtr, int value )
{
    int found ;
    TreeNodePtr parentPtr, tempNodePtr, replacementNodePtr ;
    
    /* if tree is empty */
    if ( *treePtr == NULL )
    {
        printf ( "\nTree is empty" ) ;
        return ;
    }

    parentPtr = NULL ;
    tempNodePtr = NULL;

    /* find the node to be deleted */
    searchNode ( treePtr, value, &parentPtr, &tempNodePtr, &found ) ;

    /* if the node is not found */
    if ( found == FALSE )
    {
        printf ( "\n Data not found" ) ;
        return ;
    }

    /* if the node to be deleted has two children */
    if ( tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr != NULL )
    {
        parentPtr = tempNodePtr ;
        replacementNodePtr = tempNodePtr -> rightPtr ;

        while ( replacementNodePtr -> leftPtr != NULL )
        {
            parentPtr = replacementNodePtr ;
            replacementNodePtr = replacementNodePtr -> leftPtr ;
        }

        tempNodePtr -> data = replacementNodePtr -> data ;
        tempNodePtr = replacementNodePtr ;
    }

    /* if the node to be deleted has no child */
    if ( tempNodePtr -> leftPtr == NULL && tempNodePtr -> rightPtr == NULL )
    {
        if ( parentPtr -> rightPtr == tempNodePtr )
            parentPtr -> rightPtr = NULL ;
        else
            parentPtr -> leftPtr = NULL ;

        free ( tempNodePtr ) ;
        return ;
    }

    /* if the node to be deleted has only rightPtr */
   if ( tempNodePtr -> leftPtr == NULL && tempNodePtr -> rightPtr != NULL )
    {
        if ( parentPtr -> leftPtr == tempNodePtr )
            parentPtr -> leftPtr = tempNodePtr -> rightPtr ;
        else
            parentPtr -> rightPtr = tempNodePtr -> rightPtr ;

        free ( tempNodePtr ) ;
        return ;
    }

    /* if the node to be deleted has only left child */
    if ( tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr == NULL )
    {
        if ( parentPtr -> leftPtr == tempNodePtr )
            parentPtr -> leftPtr = tempNodePtr -> leftPtr ;
        else
            parentPtr -> rightPtr = tempNodePtr -> leftPtr ;

        free ( tempNodePtr ) ;
        return ;
    }
}

void searchNode ( TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found )
{
    TreeNodePtr tempPtr ;
    tempPtr = *treePtr ;
    *found = FALSE ;
    *parentPtr = NULL ;

    while ( tempPtr != NULL )
    {
     if ( tempPtr -> data == value )
     {
       *found = TRUE ;
       *tempNodePtr = tempPtr ;
       return ;
     }

       *parentPtr = tempPtr ;
        if ( tempPtr -> data > value )
            tempPtr = tempPtr -> leftPtr ;
        else
            tempPtr = tempPtr -> rightPtr ;
    }
}