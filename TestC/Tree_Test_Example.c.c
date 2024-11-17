/* Assignment 3 Group Project
Group 1: Parts in an auto shop
by Joshua, Yihang, Chahatbir
*/
#include "link-list.h"
#include "Tree_Test.h"
#include <ctype.h>

int main()
{
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    int choice;
    char *id, *name;
    char condition;
    float price;
    char input[100];
    char anotherAction; // Added variable for another action prompt

    // Display UI and take input.
    instructions();
    fgets(input, sizeof(input), stdin);
    choice = strtol(input, NULL, 10);

    while (choice != 7)
    {
        switch (choice)
        {

        // Push to stack
        case 1:

            printf("Enter Auto Part: Part ID | Name | Price | Condition \n");
            printf("Enter Part ID: ");
            id = validString();

            printf("Enter Name of Part: ");
            name = validString();

            printf("Enter Price: ");
            price = validNumericValue();

            printf("Enter Condition (N - New, U - Used, R - Refurbished): ");
            fgets(input, sizeof(input), stdin);
            condition = input[0];

            // Validation loop
            while (tolower(condition) != 'n' && tolower(condition) != 'u' && tolower(condition) != 'r')
            {
                printf("Invalid condition entered. Please enter 'N' for New, 'U' for Used, or 'R' for Refurbished: ");
                fgets(input, sizeof(input), stdin);
                condition = input[0]; // Take only the first character again
            }
            enqueue(&headPtr, &tailPtr, id, name, toupper(condition), price); // Convert to uppercase if needed
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
            if (!isEmpty(headPtr))
            {
                printf("Enter item ID: ");
                id = validString();
                update(headPtr, id);
            }
            else
            {
                printQueue(headPtr);
            }
            break;

        case 6:
            printQueue(headPtr);
            break;

        default:
            printf("Invalid Option... Please Try Again\n");
            break;
        }

        // Show the menu again if the user chooses to continue
        instructions();
        fgets(input, sizeof(input), stdin);
        choice = strtol(input, NULL, 10);
    }
}
