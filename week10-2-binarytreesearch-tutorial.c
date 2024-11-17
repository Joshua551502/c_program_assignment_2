/*
(Binary Tree Search Tutorial Question)
 Write function binaryTreeSearch that attempts to locate a specified value in a binary search tree. The function should take as arguments a pointer to the root node of
the binary tree and a search key to be located. If the node containing the search key is found, the function should return a pointer to that node; otherwise, the function should return a NULL pointer.
*/
//ANS:


/* Exercise Solution */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* TreeNode structure definition */
struct treeNode{
  struct treeNode *leftPtr;
  int data;
  struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePtr;

/* function prototypes */

//Add Code: binaryTreeSearch () 
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int key);

void insertNode (TreeNodePtr * treePtr, int value);

int main (void)
{
  int i;			/* loop counter */
  int item;			/* random value to insert in tree */
  int searchKey;		/* value to search for */
  TreeNodePtr rootPtr = NULL; // Declare and initialise pointer to root of tree	
  TreeNodePtr searchPtr = NULL;
  // Add Code: Declare pointer to search-node 

  srand (time (NULL));		/* randomize */
  printf ("The numbers being placed in the tree are:\n");

  /* insert random values between 1 and 20 in the tree */
  for (i = 1; i <= 10; i++)
    {
      item = 1 + rand () % 20;
      printf ("%3d", item);
      insertNode (&rootPtr, item);
    }				/* end for */

  
  // add code to get search-key from user
    printf("\nEnter the search-key: ");
    scanf("%d", &searchKey);
    
  // add code to perform the search
    searchPtr = binaryTreeSearch(rootPtr, searchKey);
  /* determine if value is found or not*/
  if(searchPtr == NULL){
    printf("Key %d was [not-found]\n", searchKey);
  } else{
    printf("Key %d was [found]\n",searchPtr->data);
  }
  
}
		
/* search for key in tree */
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




 /* insert a node into the tree */
void insertNode (TreeNodePtr * treePtr, int value)
{
  /* if treePtr is NULL */
  if (*treePtr == NULL)
    {
      /* dynamically allocate memory */
      *treePtr = malloc (sizeof (TreeNode));

      /* if memory was allocated, insert node */
      if (*treePtr != NULL)
	{
	  (*treePtr)->data = value;
	  (*treePtr)->leftPtr = NULL;
	  (*treePtr)->rightPtr = NULL;
	}			/* end if */
      else
	{
	  printf ("%d not inserted. No memory available.\n", value);
	}			/* end else */
    }				/* end if */
  else
    {				/* recursively call insertNode */
      /* insert node in left subtree */
      if (value < (*treePtr)->data)
	{
	  insertNode (&((*treePtr)->leftPtr), value);
	}			/* end if */
      else
	{
	  /* insert node in right subtree */
	  if (value > (*treePtr)->data)
	    {
	      insertNode (&((*treePtr)->rightPtr), value);
	    }			/* end if */
	  else
	    {			/* duplicate value */
	      printf ("dup");
	    }			/* end else */
	}			/* end else */
    }				/* end else */
}				/* end function insertNode */


