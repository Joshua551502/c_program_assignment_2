#include "queues.h"

int main(void) { 
   QueueNodePtr headPtr = NULL;
   QueueNodePtr tailPtr = NULL;

   int choice; // user's menu choice
   int item; // integer input by user
   char name[20]; // name input by user
   float height; // height input by user

   instructions(); // display the menu
   printf("? ");
   scanf("%d", &choice);

   while (choice != 7) { 
      switch (choice) { 
         case 1:
            printf("Enter an integer value to enqueue: ");
            scanf(" %d", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
        
         case 2:
            dequeue(&headPtr, &tailPtr);
            printQueue(headPtr);
            break;

         case 3:
            front(headPtr);
            break;

         case 4:
            back(tailPtr);
            break;

         case 5:
            printQueue(headPtr);
            break;

         case 6:
            printf("Enter the data key of the item to update: ");
            scanf("%d", &item);
            printf("Enter new name: ");
            scanf("%s", name);
            printf("Enter new height: ");
            scanf("%f", &height);
            update(headPtr, item, name, height);
            printQueue(headPtr);
            break;

         default:
            puts("Invalid choice. Please select a valid option.");
            break;
      }

      instructions();
      printf("? ");
      scanf("%d", &choice);
   }

   puts("Program terminated.");
   return 0;
}