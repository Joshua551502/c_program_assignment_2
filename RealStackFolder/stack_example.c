/* Assignment 3 Group Project
Group 1: Parts in an auto shop
by Joshua, Yihang, Chahatbir
*/
#include "link-list.h"
#include "stack.h"
 int main() {
    ItemPtr startPtr = NULL;
    int choice;
    char *id, *name;
	char condition;  
    float price;
    char input[100];
    char anotherAction;  // Added variable for another action prompt

	// Display UI and take input.
    instructions();
   	fgets(input, sizeof(input), stdin);
  	choice = strtol(input, NULL, 10);

    while (choice != 7) {
        switch (choice) {
            
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
                while (condition != 'N' && condition != 'U' && condition != 'R') {
                    printf("Invalid condition entered. Please enter 'N' for New, 'U' for Used, or 'R' for Refurbished: ");
                    fgets(input, sizeof(input), stdin);
   					 condition = input[0];  // Take only the first character again
                }
                
				startPtr = push(startPtr, id, name, condition, price); 
                printStack(startPtr);
                break;

			// Pop Auto Part from Linked List
            case 2:
	            startPtr = pop(startPtr);
	            printStack(startPtr);
                break;

			// View item at top of stack
            case 3:	
                topOfStack(startPtr);
                break;
			
			// View item at bottom of stack
			case 4:
				bottomOfStack(startPtr);
				break;
			
			// Search for item in stack	
			case 5: 
			
			if(!isEmpty(startPtr)){
				printf("Enter item ID: ");
				id = validString();
				searchStack(startPtr, id);
			} else {
				printStack(startPtr);
			}
			break;
				
			// Print out and view ALL Auto Parts from Linked List
            case 6:
                printStack(startPtr);
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
