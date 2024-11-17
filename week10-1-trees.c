// Binary Tree Example
#include "week10-1-trees.h"
#include <time.h>

int main(void)
{
   int i; /* loop counter */
   int item; /* variable for random value to insert in tree */
   TreeNodePtr rootPtr = NULL;

   /* Add Code:  Create Pointer to the tree root */

   srand(time(NULL)); /* randomize */
   printf("The numbers being placed in the tree are:\n");

   /* insert random values between 0 and 14 in the tree */
   for (i = 1; i <= 10; i++) {
      item = rand() % 15;
      printf("%d ", item);
      //Insert Node Into Tree;
      insertNode(&rootPtr, item);
      // insertNodeWithDuplicates(&rootPtr,item);
   }

   puts("\n\ntraverse the tree inorder");
   /* traverse the tree inorder */
   inOrder(rootPtr);
   puts("");

   // /* traverse the tree preorder */
   // puts("\ntraverse the tree preorder");
   // preOrder(rootPtr);
   // puts("");


   // puts("\ntraverse the tree postorder");
   // /* traverse the tree postorder */
   // postOrder(rootPtr);
   // puts("");

   // puts("\ntraverse the tree reverseorder");
   // /* traverse the tree postorder */
   // reverseOrder(rootPtr);
   // puts("");

   printf("Enter Node to delete ");
   scanf("%d", &item);
   deleteNode(&rootPtr,item);
      puts("\n\ntraverse the tree inorder");
   /* traverse the tree inorder */
   inOrder(rootPtr);
   puts("");
} /* end main */


