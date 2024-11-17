#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queueNode {          // Structure definition
   int data;                // ID key as an integer            
   char name[50];           // Name field
   float height;            // Height field
   struct queueNode *nextPtr; // queueNode pointer
};                          // end structure queueNode                     

// Use typedef to rename types
typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

// function prototypes
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value, char name[], float height);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
int isEmpty(QueueNodePtr headPtr);
void printQueue(QueueNodePtr headPtr);
void instructions(void);
void front(QueueNodePtr headPtr);
void back(QueueNodePtr tailPtr);
void update(QueueNodePtr headPtr, int key);

// insert a node at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value, char name[], float height) { 
   QueueNodePtr newPtr = malloc(sizeof(QueueNode)); // Create memory for new QueueNode
   if (newPtr != NULL) { // if space is available 
      newPtr->data = value; 		// load ID data into new node
      strcpy(newPtr->name, name);   // copy name
      newPtr->height = height;      // store height
      newPtr->nextPtr = NULL;

      if (*headPtr == NULL) {		// if queue is empty, insert node at head
         *headPtr = newPtr;
      } else {						// otherwise insert at the tail
         (*tailPtr)->nextPtr = newPtr;
      }   
      *tailPtr = newPtr; // update tailPtr 
   } else {
      puts("Memory issues... Node not created");
   }
}

// remove node from queue head
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) { 
   if (isEmpty(*headPtr)) {
      puts("Queue is empty. Nothing to dequeue.");
      return;
   }
   QueueNodePtr tempPtr = *headPtr;			       // store headPtr into tempPtr              
   printf("%d being dequeued\n", tempPtr->data);	// inform user  
   *headPtr = (*headPtr)->nextPtr;			// update headPtr
   if (*headPtr == NULL) {		         // if queue is empty, update tailPtr
      *tailPtr = NULL;
   }
   free(tempPtr); // de-allocate memory from tempPtr
}

// update a node in the queue
void update(QueueNodePtr headPtr, int key) {
   QueueNodePtr currentPtr = headPtr;

   while (currentPtr != NULL && currentPtr->data != key) { // Search for node by key
      currentPtr = currentPtr->nextPtr;
   }

   if (currentPtr == NULL) {
      printf("Node with ID %d not found.\n", key);
   } else {
      char newName[50];
      float newHeight;

      printf("Enter new name: ");
      fgets(newName, sizeof(newName), stdin);
      newName[strcspn(newName, "\n")] = '\0';  // Remove newline character

      printf("Enter new height: ");
      while (scanf("%f", &newHeight) != 1) {
          printf("Invalid input. Enter a valid height: ");
          while (getchar() != '\n'); // Clear input buffer
      }
      getchar(); // Clear newline left by scanf

      strcpy(currentPtr->name, newName); // update name
      currentPtr->height = newHeight;    // update height

      printf("Node with ID %d updated successfully.\n", key);
   }
}

// return 1 if the queue is empty, 0 otherwise
int isEmpty(QueueNodePtr headPtr) { 
   return (headPtr == NULL);
}

// print the queue
void printQueue(QueueNodePtr headPtr) { 
   QueueNodePtr currentPtr = headPtr;

   if (currentPtr == NULL) {
      puts("Queue is empty.");
   } else {
      puts("The queue is:");
      while (currentPtr != NULL) {
         printf("ID: %d, Name: %s, Height: %.2f\n ", currentPtr->data, currentPtr->name, currentPtr->height);
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
          "   3 to get front of queue\n"
          "   4 to get back of queue\n"
          "   5 to print items in queue\n"
          "   6 to update student in the queue\n"
          "   7 to end\n");
}

void front(QueueNodePtr headPtr) {
   if (headPtr != NULL) {
      printf("%d is at the front of the Queue\n", headPtr->data);
   } else {
      puts("Queue is empty.");
   }
}

void back(QueueNodePtr tailPtr) {
   if (tailPtr != NULL) {
      printf("%d is at the back of the Queue\n", tailPtr->data);
   } else {
      puts("Queue is empty.");
   }
}