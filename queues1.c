#include "queues1.h"
int main(void) { 
   QueueNodePtr headPtr = NULL; 	
   QueueNodePtr tailPtr = NULL;

   int choice, item;
   char name[50];
   float height;

   instructions();
   printf("%s", "? ");
   while (scanf("%d", &choice) == 1) {
      getchar(); // Clear newline character from the input buffer

      switch(choice) { 
         case 1:
            printf("Enter ID: ");
            scanf("%d", &item);
            getchar(); // Clear newline from input buffer
            printf("Enter name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';  // Remove newline character
            printf("Enter height: ");
            while (scanf("%f", &height) != 1) {
               printf("Invalid input. Enter a valid height: ");
               while (getchar() != '\n'); // Clear input buffer
            }
            getchar(); // Clear newline left by scanf
            enqueue(&headPtr, &tailPtr, item, name, height);
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
            printf("Enter ID of the node to update: ");
            scanf("%d", &item);
            getchar(); // Clear newline character
            update(headPtr, item);
            printQueue(headPtr); 
            break;

         default:
            puts("Invalid choice.");
            break;
      }

      instructions();
      printf("%s", "? ");
   }

   puts("End of run.");
}