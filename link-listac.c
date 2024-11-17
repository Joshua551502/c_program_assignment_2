#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link-list.h"

/******* Function Definitions ******/


// Create a part and return pointer to it
PartPtr makePart(int id, char name[20], char category, float price) {
    PartPtr newPtr = (PartPtr)malloc(sizeof(Part));
    if (newPtr == NULL) {
        puts("Memory allocation failed... Part not created.");
        return NULL;  // Ensure we return NULL if memory allocation fails
    } 
    // Assign values to the newly created part
    newPtr->partId = id;
    strcpy(newPtr->partName, name);  // Ensure name is copied safely
    newPtr->partCategory = category;
    newPtr->partPrice = price;
    newPtr->nextPtr = NULL;

    return newPtr;
}

// Add part to list and figure out its new position within the list
PartPtr addPart(PartPtr sPtr, int id, char name[20], char category, float price) {
    PartPtr newPtr, previousPtr, currentPtr;
    newPtr = makePart(id, name, category, price);  // Create the new part

    if (newPtr == NULL) {
        puts("Failed to add part. Memory allocation failed.");
        return sPtr;
    }

    previousPtr = NULL;
    currentPtr = sPtr;

    // Traverse the list to find the correct position based on partId
    while (currentPtr != NULL && id > currentPtr->partId) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    // Insert at the beginning of the list
    if (previousPtr == NULL) {
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    } else { // Insert in between or at the end
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }

    return sPtr;
}

// Remove a part from the list
PartPtr removePart(PartPtr sPtr, int id) {
    PartPtr previousPtr, currentPtr;

    if (sPtr == NULL) {
        printf("No parts available for deletion.\n");
        return sPtr;
    }

    // If the part to be deleted is the first in the list
    if (id == sPtr->partId) {
        sPtr = sPtr->nextPtr;
        printf("Part with ID %d deleted.\n", id);
        return sPtr;
    }

    previousPtr = sPtr;
    currentPtr = sPtr->nextPtr;

    // Traverse the list to find the part
    while (currentPtr != NULL && currentPtr->partId != id) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    // If the part is found
    if (currentPtr != NULL) {
        previousPtr->nextPtr = currentPtr->nextPtr;
        printf("Part with ID %d deleted successfully.\n", id);
    } else {
        printf("Part with ID %d not found.\n", id);
    }

    return sPtr;
}

// View a specific part from the list
void viewPart(PartPtr sPtr, int id) {
    while (sPtr != NULL && sPtr->partId != id) {
        sPtr = sPtr->nextPtr;
    }

    if (sPtr == NULL) {
        printf("Part with ID %d not found.\n", id);
    } else {
        printf("Part found: ID: %d, Name: %s, Category: %c, Price: %.2f\n", sPtr->partId, sPtr->partName, sPtr->partCategory, sPtr->partPrice);
    }
}

// Print the entire list of parts
void printList(PartPtr sPtr) {
    PartPtr tempPtr = sPtr;

    if (tempPtr == NULL) {
        puts("No parts available in the shop.");
    } else {
        puts("The parts available in the auto shop are:");
        while (tempPtr != NULL) {
            printf("ID: %d, Name: %s, Category: %c, Price: %.2f\n", tempPtr->partId, tempPtr->partName, tempPtr->partCategory, tempPtr->partPrice);
            tempPtr = tempPtr->nextPtr;
        }
    }
}


// Menu function specific to Parts in an Auto Shop
void menu() {
    printf("\nAuto Shop Parts Menu\n");
    printf("\t1: Insert a new part into the list\n");
    printf("\t2: Remove an existing part from the list\n");
    printf("\t3: View details of a specific part\n");
    printf("\t4: Print the list of all available parts\n");
    printf("\t5: Exit\n");
    printf("Please select an option: ");
}

// Validate input for part insertion
int validateInput(char *input, int *id, char *category, char *name, float *price) {
    char priceStr[20];

    printf("Enter Part ID (numeric): ");
    fgets(input, 20, stdin);
    *id = (int)strtol(input, NULL, 10);

    printf("Enter Part Category (single character): ");
    fgets(input, 5, stdin);
    *category = input[0];

    printf("Enter Part Name (up to 20 characters): ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Part Price: ");
    fgets(priceStr, 20, stdin);
    *price = strtof(priceStr, NULL);

    return 1;
}

// Main function
int main() {
    PartPtr startPtr = NULL; // Initialize the start of the list
    char input[20], name[20];
    int choice, id;
    char category;
    float price;

    // Display the menu and process user input
    menu();
    fgets(input, 5, stdin);
    choice = (int)strtol(input, NULL, 10);  // Safe input conversion

    while (choice != 5) {
        switch (choice) {
            case 1: // Insert Part
                if (validateInput(input, &id, &category, name, &price)) {
                    startPtr = addPart(startPtr, id, name, category, price);
                    printList(startPtr);
                }
                break;

            case 2: // Remove Part
                printf("\nEnter Part ID to delete: ");
                fgets(input, 20, stdin);
                id = (int)strtol(input, NULL, 10);
                startPtr = removePart(startPtr, id);
                printList(startPtr);
                break;

            case 3: // View Part
                printf("\nEnter Part ID to view: ");
                fgets(input, 20, stdin);
                id = (int)strtol(input, NULL, 10);
                viewPart(startPtr, id);
                break;

            case 4: // Print List of Parts
                printList(startPtr);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        // Display the menu again for the next choice
        menu();
        fgets(input, 5, stdin);
        choice = (int)strtol(input, NULL, 10);  // Safe input conversion
    }

    printf("Exiting the Auto Shop Parts System.\n");
    return 0;
}
