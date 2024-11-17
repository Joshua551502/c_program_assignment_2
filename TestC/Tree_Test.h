

// Operating and maintaining a queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure definition
struct queueNode
{
    char itemID[10];    // Unique Alphanumeric Identifier
    char itemName[20];  // Part Name
    char itemCondition; // Part Condition ('N' for New, 'U' for Used, 'R' for Refurbished)
    float itemPrice;    // Part Price
    struct queueNode *nextPtr;
}; // end structure queueNode

// Use typedef to rename types
typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

// function prototypes
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char id[], char name[], char condition, float price);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void front(QueueNodePtr headPtr);
void back(QueueNodePtr tailPtr);
void update(QueueNodePtr headPtr, char key[]);
bool isEmpty(QueueNodePtr headPtr);
bool isUnique(QueueNodePtr headPtr, char itemID[]);

/*Function Definitions*/

// insert a node in at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char id[], char name[], char condition, float price)
{
    QueueNodePtr newPtr = (QueueNodePtr)malloc(sizeof(QueueNode));
    if (newPtr == NULL)
    {
        puts("Memory Issues... Node not created");
        return;
    }

    // Check for unique ID
    if (!isUnique(*headPtr, id))
    {
        puts("Duplicate item ID, cannot enqueue.");
        free(newPtr);
        return;
    }

    strcpy(newPtr->itemID, id);
    strcpy(newPtr->itemName, name);
    newPtr->itemCondition = condition;
    newPtr->itemPrice = price;
    newPtr->nextPtr = NULL;

    // Insert the new node into the queue
    if (*headPtr == NULL)
    {
        *headPtr = newPtr;
    }
    else
    {
        (*tailPtr)->nextPtr = newPtr;
    }
    *tailPtr = newPtr; // Update tailPtr to point to new node
}

// remove node from queue head
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    QueueNodePtr tempPtr;           // Declare temporary node pointer to isolate node to be deleted
    tempPtr = *headPtr;             // store headPtr into tempPtr
    *headPtr = (*headPtr)->nextPtr; // update headPtr
    if (*headPtr == NULL)
    {                    // if queue is empty, update tailPtr
        *tailPtr = NULL; // add code to update tailPtr
    }

    free(tempPtr); // de-allocate memory from tempPtr
}

// return 1 if the queue is empty, 0 otherwise
bool isEmpty(QueueNodePtr headPtr)
{
    return headPtr == NULL; // return queue is empty if headPtr == NULL
}

// print the queue
void printQueue(QueueNodePtr headPtr)
{
    QueueNodePtr currentPtr = headPtr; // set currentPtr to head of queue
    // if queue is empty
    if (currentPtr == NULL)
    {
        puts("\n Queue is empty.\n");
    } // end if
    else
    {
        puts("The queue is:");

        // while not end of queue
        while (currentPtr != NULL)
        {

            printf("ID: %s | Name: %s | Price: %.2f | Condition: %c\n", currentPtr->itemID, currentPtr->itemName, currentPtr->itemPrice, currentPtr->itemCondition);
            currentPtr = currentPtr->nextPtr;
        } // end while
        puts("");
    } // end else
} // end function printQueue

// display program instructions to user
void instructions(void)
{
    printf("AUTO PARTS ORDER QUEUE\n"
           "Enter your choice:\n"
           "   1 to add an auto part to the queue\n"
           "   2 to remove an auto part from the queue\n"
           "   3 view front of the order queue\n"
           "   4 view back of the order queue\n"
           "   5 update queue node \n "
           "   6 print queue\n"
           "   7 to end\n");
} // end function instructions

void front(QueueNodePtr headPtr)
{
    printf("Front of Queue: ID=%s, Name=%s, Condition=%c, Price=%.2f \n",
           headPtr->itemID, headPtr->itemName, headPtr->itemCondition, headPtr->itemPrice, headPtr->itemCondition);
}
void back(QueueNodePtr tailPtr)
{
    printf("Back of Queue: ID=%s, Name=%s, Condition=%c, Price=%.2f \n", tailPtr->itemID, tailPtr->itemName, tailPtr->itemCondition, tailPtr->itemPrice, tailPtr->itemCondition);
}

// Checks for Duplicate item ID to ensure each item is unique before pushing new item
bool isUnique(QueueNodePtr headPtr, char itemID[])
{
    QueueNodePtr currentPtr = headPtr;
    int position = 0;

    while (currentPtr != NULL)
    {
        if (strcmp(itemID, currentPtr->itemID) == 0)
        {
            puts("DUPLICATE ITEM FOUND");
            printf("Item found at position %d: ID=%s, Name=%s, Condition=%c, Price=%.2f\n",
                   position + 1, currentPtr->itemID, currentPtr->itemName, currentPtr->itemCondition, currentPtr->itemPrice);
            return false;
        }
        currentPtr = currentPtr->nextPtr;
        position++;
    }
    return true;
}

void update(QueueNodePtr headPtr, char key[])
{
    QueueNodePtr currentPtr = headPtr;
    int position = 0;

    while (currentPtr != NULL && strcmp(key, currentPtr->itemID) != 0)
    {
        currentPtr = currentPtr->nextPtr;
        position++;
    }

    if (currentPtr == NULL)
    {
        printf("Item with ID=%s not found in the queue.\n", key);
    }
    else
    {
        char input[100];
        printf("Item found at position %d: ID=%s, Name=%s,\n",
               position + 1, currentPtr->itemID, currentPtr->itemName);

        printf("Enter Auto Part: Name | Price | Condition \n");

        printf("Enter Name of Part: ");
        strcpy(currentPtr->itemName, validString());

        printf("Enter Price: ");
        currentPtr->itemPrice = validNumericValue();

        printf("Enter Condition (N - New, U - Used, R - Refurbished): ");
        fgets(input, sizeof(input), stdin);
        currentPtr->itemCondition = input[0];

        // Validation loop
        while (currentPtr->itemCondition != 'N' && currentPtr->itemCondition != 'n' &&
               currentPtr->itemCondition != 'U' && currentPtr->itemCondition != 'u' &&
               currentPtr->itemCondition != 'R' && currentPtr->itemCondition != 'r')
        {
            printf("Invalid condition entered. Please enter 'N' for New, 'U' for Used, or 'R' for Refurbished: ");
            fgets(input, sizeof(input), stdin);
            currentPtr->itemCondition = input[0];
        }
    }
}
