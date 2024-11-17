#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct queueNode {
   int data;
   char name[20];
   float height;
   struct queueNode *nextPtr;
};

// typedefs for convenience
typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

/*Function Definitions*/
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
int isEmpty(QueueNodePtr *headPtr);
void printQueue(QueueNodePtr headPtr);
void instructions(void);
void front(QueueNodePtr headPtr);
void back(QueueNodePtr tailPtr);
void update(QueueNodePtr headPtr, int key, char name[20], float height);

// insert a node at the queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value) {
   QueueNodePtr newPtr = malloc(sizeof(QueueNode));

   if (newPtr != NULL) {
      newPtr->data = value;
      strcpy(newPtr->name, ""); // Initialize name with an empty string
      newPtr->height = 0.0; // Initialize height with zero
      newPtr->nextPtr = NULL;

      if (*headPtr == NULL) {
         *headPtr = newPtr;
      } else {
         (*tailPtr)->nextPtr = newPtr;
      }
      *tailPtr = newPtr;
   } else {
      puts("Memory issues... Node not created.");
   }
}

// remove node from queue head
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) { 
   QueueNodePtr tempPtr = *headPtr;
   printf("%d dequeued\n", tempPtr->data);
   *headPtr = (*headPtr)->nextPtr;

   if (*headPtr == NULL) {
      *tailPtr = NULL;
   }
   free(tempPtr);
}

// check if queue is empty
int isEmpty(QueueNodePtr *headPtr) { 
   return (*headPtr == NULL);
}

// print the queue
void printQueue(QueueNodePtr headPtr) { 
   QueueNodePtr currentPtr = headPtr;
   
   if (currentPtr == NULL) {
      puts("\nQueue is empty.\n");
   } else {
      puts("The queue is:");
      while (currentPtr != NULL) { 
         printf("Data: %d, Name: %s, Height: %.2f --> ", currentPtr->data, currentPtr->name, currentPtr->height);
         currentPtr = currentPtr->nextPtr;
      }
      puts("NULL\n");
   }
}

// display program instructions to user
void instructions(void) { 
   printf("Enter your choice:\n"
          "   1 to add student to the queue\n"
          "   2 to remove student from the queue\n"
          "   3 to display the front of the queue\n"
          "   4 to display the back of the queue\n"
          "   5 to display all items in the queue\n"
          "   6 to update an item in the queue\n"
          "   7 to end\n");
}

void front(QueueNodePtr headPtr) {
   printf("%d is at the front of the queue\n", headPtr->data);
}

void back(QueueNodePtr tailPtr) {
   printf("%d is at the back of the queue\n", tailPtr->data);
}

void update(QueueNodePtr headPtr, int key, char name[20], float height) {
   QueueNodePtr currentPtr = headPtr;

 
   while (currentPtr != NULL && currentPtr->data != key) {
      currentPtr = currentPtr->nextPtr;
   }

   if (currentPtr != NULL) { 
      strcpy(currentPtr->name, name);
      currentPtr->height = height;
      printf("Node with key %d updated: Name = %s, Height = %.2f\n", key, name, height);
   } else {
      printf("Node with key %d not found in the queue.\n", key);
   }
}