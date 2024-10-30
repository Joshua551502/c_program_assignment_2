#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition with Alphanumeric ID
struct item {
    char itemID[10];       // Unique Alphanumeric Identifier
    char itemName[20];     // Part Name
    float itemPrice;       // Part Price
    struct item *nextPtr;
};

typedef struct item Item;
typedef struct item *ItemPtr;

/* Function Prototypes */
ItemPtr makeItem(char id[10], char name[20], float price);
ItemPtr addItem(ItemPtr sPtr, char id[10], char name[20], float price);
void printList(ItemPtr sPtr);
ItemPtr removeItem(ItemPtr sPtr, char id[10]);
void viewItem(ItemPtr sPtr, char id[10]);
void menu();
void clearInputBuffer();

/******* Function Definitions ******/
ItemPtr makeItem(char id[10], char name[20], float price) {
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item));
    if (newPtr == NULL) {
        puts("Memory allocation failed... Item not created");
    } else {
        strcpy(newPtr->itemID, id);
        strcpy(newPtr->itemName, name);
        newPtr->itemPrice = price;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

ItemPtr addItem(ItemPtr sPtr, char id[10], char name[20], float price) {
    ItemPtr newPtr, previousPtr, currentPtr;
    previousPtr = NULL;
    currentPtr = sPtr;
    newPtr = makeItem(id, name, price);

    // Insert in order by alphanumeric ID
    while (currentPtr != NULL && strcmp(id, currentPtr->itemID) > 0) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if (previousPtr == NULL) {  // Insert at start of list
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    } else {  // Insert in between or at the end
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
    return sPtr;
}

void printList(ItemPtr sPtr) {
    ItemPtr tempPtr = sPtr;
    if (tempPtr == NULL) {
        puts("List is empty... Nothing to print");
    } else {
        puts("Auto Shop Inventory:");
        while (tempPtr != NULL) {
            printf("ID: %s, Part: %s, Price: %.2f\n", tempPtr->itemID, tempPtr->itemName, tempPtr->itemPrice);
            tempPtr = tempPtr->nextPtr;
        }
        puts("");
    }
}

ItemPtr removeItem(ItemPtr sPtr, char id[10]) {
    ItemPtr previousPtr = NULL, currentPtr = sPtr, tempPtr = NULL;
    if (sPtr == NULL) {
        puts("List is empty... nothing to delete");
        return NULL;
    } 

    // Search for item by ID
    while (currentPtr != NULL && strcmp(id, currentPtr->itemID) != 0) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if (currentPtr == NULL) {  // ID not found
        printf("ID %s not found in the list\n", id);
    } else if (previousPtr == NULL) {  // Item is at the front
        tempPtr = sPtr;
        printf("Part %s (%s) deleted...\n", tempPtr->itemName, tempPtr->itemID);
        sPtr = sPtr->nextPtr;
        free(tempPtr);
    } else {  // Item is in the middle or end
        tempPtr = currentPtr;
        printf("Part %s (%s) deleted...\n", tempPtr->itemName, tempPtr->itemID);
        previousPtr->nextPtr = currentPtr->nextPtr;
        free(tempPtr);
    }
    return sPtr;
}

void viewItem(ItemPtr sPtr, char id[10]) {
    ItemPtr currentPtr = sPtr;
    int position = 0;

    if (sPtr == NULL) {
        puts("List is empty... nothing to view");
        return;
    }

    // Search for the item by ID
    while (currentPtr != NULL && strcmp(id, currentPtr->itemID) != 0) {
        currentPtr = currentPtr->nextPtr;
        position++;
    }

    if (currentPtr == NULL) {  // ID not found
        printf("ID %s not found in the list\n", id);
    } else {  // Item found
        printf("Part %s (%s) is at position %d\n", currentPtr->itemName, currentPtr->itemID, position + 1);
    }
}

void menu() {
    printf("\t1: Insert Part into Ordered List\n");
    printf("\t2: Remove Part from List\n");
    printf("\t3: View Part in List\n");
    printf("\t4: Print List of Parts\n");
    printf("\t5: Exit\n");
    printf("\tEnter Choice: ");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}