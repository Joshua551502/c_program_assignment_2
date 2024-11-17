#include <stdio.h>
#include <stdlib.h>
#define MaxQ 10
#define EmptyValue -9999

// Set Predefined Constant for Queue size
typedef struct queueType {
    int head;
    int tail;
    int storeQ[MaxQ];
} QueueType, *QueueTypePtr;

// Function Prototypes
QueueTypePtr initQueue();                  /*Initialise queue       */
int isEmpty(QueueTypePtr qPtr);            /*Check if queue is empty*/
void enqueue(QueueTypePtr qPtr, int value);/*Add to queue           */
int dequeue(QueueTypePtr qPtr);            /*Remove from Queue      */

// Function Definitions
QueueTypePtr initQueue()                   /*Initialise queue       */
{
    QueueTypePtr qPtr = malloc(sizeof(QueueType));
    if (qPtr != NULL) {
        qPtr->head = 0;
        qPtr->tail = 0;
    } else {
        puts("Memory Issues... Queue not created");
    }
    return qPtr;
}

int isEmpty(QueueTypePtr qPtr)             /*Check if queue is empty*/
{
    return (qPtr->head == qPtr->tail);
}

void enqueue(QueueTypePtr qPtr, int value) /*Add to queue*/
{
    int nextTail = (qPtr->tail + 1) % MaxQ; // Calculate the next tail position in circular fashion
    if (nextTail == qPtr->head) {           // Check if queue is full
        puts("Queue is full...");
        return;
    }

    while (value != 0) {
        qPtr->storeQ[qPtr->tail] = value % 10;  // Store the last digit of value at the current tail
        value /= 10;                            // Divide value by 10 to get the next digit
        qPtr->tail = nextTail;                  // Update tail position
        nextTail = (qPtr->tail + 1) % MaxQ;     // Recalculate next tail in circular fashion

        if (nextTail == qPtr->head) {           // Check if queue is full after adding
            puts("Queue is full...");
            return;
        }
    }
}


int dequeue(QueueTypePtr qPtr)             /*Remove from Queue      */
{
    if (isEmpty(qPtr)) {                    // Check if queue is empty
        puts("Queue is empty... nothing to dequeue");
        return EmptyValue;
    }
    int dequeuedValue = qPtr->storeQ[qPtr->head]; // Get the value at head
    qPtr->head = (qPtr->head + 1) % MaxQ;         // Move head in circular fashion
    return dequeuedValue;                   // Return dequeued value
}
