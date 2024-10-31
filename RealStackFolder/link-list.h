#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Structure Definition with Alphanumeric ID for Stack
struct item {
    char itemID[10];        // Unique Alphanumeric Identifier
    char itemName[20];      // Part Name
    char itemCondition;     // Part Condition ('N' for New, 'U' for Used, 'R' for Refurbished)
    float itemPrice;        // Part Price
    struct item *nextPtr;
};

typedef struct item Item;
typedef struct item *ItemPtr;

/* Function Prototypes */
ItemPtr createItem(char id[10], char name[20], char condition, float price);
ItemPtr push(ItemPtr stackTop, char id[10], char name[20], char condition, float price);
ItemPtr pop(ItemPtr *stackTop);
void topOfStack(ItemPtr stackTop);
void bottomOfStack(ItemPtr stackTop);
void printStack(ItemPtr stackTop);
void stackMenu();
bool isEmpty(ItemPtr stackTop);  // Function prototype for isEmpty
float validNumericValue();
char* validString();

/******* Function Definitions ******/

// Check if stack is empty
bool isEmpty(ItemPtr stackTop) {
    return stackTop == NULL;
}

// Create new item node
ItemPtr createItem(char id[10], char name[20], char condition, float price) {
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item));
    if (newPtr != NULL) {
        strcpy(newPtr->itemID, id);
        strcpy(newPtr->itemName, name);
        newPtr->itemCondition = condition;
        newPtr->itemPrice = price;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

// Push new item onto stack
ItemPtr push(ItemPtr stackTop, char id[10], char name[20], char condition, float price) {
    ItemPtr newPtr = createItem(id, name, condition, price);
    if (newPtr != NULL) {
        newPtr->nextPtr = stackTop;
        stackTop = newPtr;
        printf("Part %s (%s) has been pushed onto the stack.\n", name, id);
    }
    return stackTop;
}

// Pop item from stack
ItemPtr pop(ItemPtr *stackTop) {
    if (*stackTop == NULL) {
        puts("Stack is empty... nothing to pop.");
        return NULL;
    }
    ItemPtr tempPtr = *stackTop;
    printf("Part %s (%s) has been popped from the stack.\n", tempPtr->itemName, tempPtr->itemID);
    *stackTop = (*stackTop)->nextPtr;
    free(tempPtr);  // Free memory to avoid memory leak
    return *stackTop;
}

// Display top item on stack
void topOfStack(ItemPtr stackTop) {
    if (stackTop == NULL) {
        puts("Stack is empty.");
    } else {
        printf("Top of Stack: ID: %s, Part: %s, Price: %.2f, Condition: %c\n",
               stackTop->itemID, stackTop->itemName, stackTop->itemPrice, stackTop->itemCondition);
    }
}

// Display bottom item on stack
void bottomOfStack(ItemPtr stackTop) {
    if (stackTop == NULL) {
        puts("Stack is empty.");
        return;
    }
    while (stackTop->nextPtr != NULL) {
        stackTop = stackTop->nextPtr;
    }
    printf("Bottom of Stack: ID: %s, Part: %s, Price: %.2f, Condition: %c\n",
           stackTop->itemID, stackTop->itemName, stackTop->itemPrice, stackTop->itemCondition);
}

// Print all items in the stack
void printStack(ItemPtr stackTop) {
    if (stackTop == NULL) {
        puts("Stack is empty... Nothing to print.");
    } else {
        puts("Auto Shop Inventory Stack:");
        while (stackTop != NULL) {
            printf("ID: %s, Part: %s, Price: %.2f, Condition: %c\n",
                   stackTop->itemID, stackTop->itemName, stackTop->itemPrice, stackTop->itemCondition);
            stackTop = stackTop->nextPtr;
        }
    }
}

// Numeric input validation
float validNumericValue() {
    char input[100];
    float price;
    bool isValid = false;
    
    while (!isValid) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        
        char *end;
        price = strtof(input, &end);
        if (end == input || *end != '\0') {
            printf("Invalid input. Enter a numeric value: ");
        } else {
            isValid = true;
        }
    }
    return price;
}

// String input validation
char* validString() {
    char *input = (char *)malloc(100 * sizeof(char));
    bool isValid = false;

    while (!isValid) {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        
        if (strlen(input) == 0) {
            printf("Input is empty. Enter something to continue: ");
        } else {
            isValid = true;
        }
    }
    return input;
}

// Menu for stack operations
void stackMenu() {
    puts("STACK OPERATIONS");
    printf("1) Top of Stack\n");
    printf("2) Bottom of Stack\n");
    printf("3) Push\n");
    printf("4) Pop\n");
    printf("5) Print all data items\n");
    printf("6) Exit Stack Application\n");
    printf("Enter Choice: ");
}
