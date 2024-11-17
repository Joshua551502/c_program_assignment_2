#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> 

/* Linked List Group Project
Group 1: Parts in an auto shop
by Joshua, Yihang, Chahatbir
*/

// Structure Definition with Alphanumeric ID
struct item {
    char itemID[10];       // Unique Alphanumeric Identifier
    char itemName[20];     // Part Name
    char itemCondition;    // Part Condition ('N' for New, 'U' for Used, 'R' for Refurbished) 
    float itemPrice;       // Part Price
    struct item *nextPtr;
};

typedef struct item Item;
typedef struct item *ItemPtr;

/* Function Prototypes */
ItemPtr makeItem(char id[10], char name[20], char condition, float price); // Updated to include condition
ItemPtr addItem(ItemPtr sPtr, char id[10], char name[20], char condition, float price); // Updated to include condition
void printList(ItemPtr sPtr);
ItemPtr removeItem(ItemPtr sPtr, char id[10]);
void viewItem(ItemPtr sPtr, char id[10]);
void menu();
void clearInputBuffer();
float validNumericValue();
char* validString();


/******* Function Definitions ******/
ItemPtr makeItem(char id[10], char name[20], char condition, float price) { // Updated to include condition
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item));
    if (newPtr == NULL) {
        puts("Memory allocation failed... Item not created");
    } else {
        strcpy(newPtr->itemID, id);
        strcpy(newPtr->itemName, name);
        newPtr->itemCondition = condition; // Added to handle condition
        newPtr->itemPrice = price;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

ItemPtr addItem(ItemPtr sPtr, char id[10], char name[20], char condition, float price) { // Updated to include condition
    ItemPtr newPtr, previousPtr, currentPtr;
    previousPtr = NULL;
    currentPtr = sPtr;
    
    newPtr = makeItem(id, name, condition, price); // Pass condition

    // Insert in order by alphanumeric ID
    while (currentPtr != NULL && strcmp(id, currentPtr->itemID) > 0) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    
    // Check for a duplicate Part ID
    if (currentPtr != NULL && strcmp (id, currentPtr->itemID) == 0){
    	printf("Duplicate Part ID %s Not inserting \n", id);
		return sPtr; // Return without adding the item.
		}
		
    if (previousPtr == NULL) {  // Insert at start of list
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    } else {  // Insert in between or at the end
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
    // Confirmation message after adding the part
    printf("Part %s (%s) has been added successfully.\n", name, id);
    return sPtr;
}

void printList(ItemPtr sPtr) {
    ItemPtr tempPtr = sPtr;
    if (tempPtr == NULL) {
        puts("List is empty... Nothing to print");
    } else {
        puts("Auto Shop Inventory:");
        while (tempPtr != NULL) {
            printf("ID: %s, Part: %s, Price: %.2f, Condition: %c\n", tempPtr->itemID, tempPtr->itemName, tempPtr->itemPrice, tempPtr->itemCondition); // Output condition
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

// View item inside linked list
void viewItem(ItemPtr sPtr, char id[10]) {
    ItemPtr currentPtr = sPtr;
    int position = 0;

	// Check if list is empty
    if (sPtr == NULL) {
        puts("List is empty... nothing to view");
        return;
    }

    // Search for the item by ID
    while (currentPtr != NULL && strcmp(id, currentPtr->itemID) != 0) {
        currentPtr = currentPtr->nextPtr;
        position++;
    }

	// Check if item ID is found
    if (currentPtr == NULL) {  // ID not found
        printf("ID %s not found in the list\n", id);
    } else {  // Item found
        printf("Part %s (%s) is at position %d\n", currentPtr->itemName, currentPtr->itemID, position + 1);
    }
}


// Check if numeric value is entered
float validNumericValue() {
	bool isValid = false;
	char input[100];
	float price; 
	while (!isValid){
		fgets(input, 100, stdin);
		input[strcspn(input, "\n")] = '\0';  // Remove newline character
		
		// If user enters empty string
		if(strlen(input) == 0) {
			printf("Input is empty. Enter a numeric value: ");
			continue;
		}
		
		// Validate numeric input
        int dotCount = 0;
        isValid = true;
		
				
		 // Check for negative sign, digits, and decimal point
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == '-') {
                // Allow negative sign only at the start
                if (i != 0) {
                    isValid = false;
                    break;
                }
            } else if (input[i] == '.') {
                // Allow only one decimal point
                if (++dotCount > 1) {
                    isValid = false;
                    break;
                }
            } else if (!isdigit(input[i])) {
                // If it's not a digit and not a valid sign or decimal point
                isValid = false;
                break;
            }
        }

        // If valid, convert to float
        if (isValid) {
            price = strtof(input, NULL);
            // Check if conversion was successful (not 0 and input wasn't "0" or empty)
            if (price == 0.0f && strcmp(input, "0") != 0) {
                printf("Conversion error. Enter a valid numeric value: ");
                isValid = false;
            }
        } else {
            printf("Input is not valid. Enter a numeric value: ");
        }
	
	
	}
	return price;
}

// Check if string is empty or not
char* validString() {
	bool isValid = false;
	char *input = (char *)malloc(100 * sizeof(char)); // Dynamically allocate memory for the input string
	while (!isValid){
		fgets(input, 100, stdin);  // Read ID
        input[strcspn(input, "\n")] = '\0';  // Remove trailing newline
		// If user enters empty string
		if(strlen(input) == 0) {
			printf("Input is empty. Enter something to continue: ");
			continue;
		}
		isValid = true;
	}
	
	return input;
}

void menu() {
	puts("\tAUTO PARTS INVENTORY SYSTEM");
    printf("\t1: Insert Part into Ordered List\n");
    printf("\t2: Remove Part from List\n");
    printf("\t3: View Part in List\n");
    printf("\t4: Print List of Parts\n");
    printf("\t5: Exit\n");
    printf("\tEnter Choice: ");
}

