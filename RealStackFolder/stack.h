#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*.......Function Definitions .....*/

// Pushes a new item onto the stack
ItemPtr push(ItemPtr topPtr, char itemID[], char itemName[], char itemCondition, float itemPrice) {
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item)); // Create memory for new Item

    if (newPtr != NULL) { // Push new Item onto top-of-stack
        strcpy(newPtr->itemID, itemID);
        strcpy(newPtr->itemName, itemName);
        newPtr->itemCondition = itemCondition;
        newPtr->itemPrice = itemPrice;
        newPtr->nextPtr = topPtr;
        topPtr = newPtr;
    } else {
        printf("Item not inserted. No memory available.\n");
    }
    return topPtr; // return pointer to top-of-stack;
}

// Pops an item from the stack
ItemPtr pop(ItemPtr topPtr) {
    if (isEmpty(topPtr)) {
        printf("Stack is empty, cannot pop.\n");
        return NULL;
    }

    ItemPtr tempPtr = topPtr;
    printf("Popped item: ID=%s, Name=%s, Condition=%c, Price=%.2f\n",
           tempPtr->itemID, tempPtr->itemName, tempPtr->itemCondition, tempPtr->itemPrice, tempPtr->itemCondition);
    topPtr = topPtr->nextPtr;
    free(tempPtr);

    return topPtr; // return pointer to top-of-stack
}

// Prints all items in the stack
void printStack(ItemPtr topPtr) {
    if (isEmpty(topPtr)) {
        puts("Stack is empty.");
    } else {
        printf("The stack is:\n");
        ItemPtr currentPtr = topPtr;
        while (currentPtr != NULL) {
            printf("ID=%s, Name=%s, Condition=%c, Price=%.2f <- ",
                   currentPtr->itemID, currentPtr->itemName,
                   currentPtr->itemCondition, currentPtr->itemPrice, currentPtr->itemCondition);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

// Checks if the stack is empty
int isEmpty(ItemPtr topPtr) {
    return (topPtr == NULL);
}

// Displays the item at the top of the stack
void topOfStack(ItemPtr topPtr) {
    if (!isEmpty(topPtr)) {
        printf("Top of stack item: ID=%s, Name=%s, Condition=%c, Price=%.2f\n",
               topPtr->itemID, topPtr->itemName, topPtr->itemCondition, topPtr->itemPrice, topPtr->itemCondition);
    } else {
        printf("Stack is empty.\n");
    }
}

// Prints menu instructions
void instructions(void) {
    printf(
		"AUTO PARTS SYSTEM: STACK Linked List \n"
			"Enter choice:\n"
           "1 to push an Auto Part on the stack\n"
           "2 to pop a Auto Part off the stack\n"
           "3 to view the top of the stack\n"
           "4 to view the bottom of the stack\n"
           "5 to search the stack by ID\n"
           "6 to print the stack\n"
           "7 to end the program\n");
}

// Displays the item at the bottom of the stack
void bottomOfStack(ItemPtr topPtr) {
    if (isEmpty(topPtr)) {
        printf("Stack is empty.\n");
        return;
    }

    ItemPtr previousPtr = NULL, currentPtr = topPtr;
    while (currentPtr != NULL) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    printf("Bottom of stack item: ID=%s, Name=%s, Condition=%c, Price=%.2f\n",
           previousPtr->itemID, previousPtr->itemName, previousPtr->itemCondition, previousPtr->itemPrice, previousPtr->itemCondition);
}

// Searches for an item by ID in the stack
void searchStack(ItemPtr topPtr, char itemID[]) {
    ItemPtr currentPtr = topPtr;
    int position = 1;
    while (currentPtr != NULL && strcmp(itemID, currentPtr->itemID) != 0) {
        currentPtr = currentPtr->nextPtr;
        position++;
    }

    if (currentPtr == NULL) {
        printf("Item with ID=%s not found in the stack.\n", itemID);
    } else {
        printf("Item found at position %d: ID=%s, Name=%s, Condition=%c, Price=%.2f\n",
               position, currentPtr->itemID, currentPtr->itemName, currentPtr->itemCondition, currentPtr->itemPrice);
    }
}
