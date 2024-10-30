#include "stack.h"

int main(void) {
    // Create stack pointer
    StackNodePtr stackPtr = NULL;

    int choice;
    int value;

    instructions();
    printf("? ");
    
    // Using fgets instead of scanf for input
    char input[10];  // Buffer for storing user input
    
    // Read and process user input until choice is 7 (exit)
    while (true) {
        fgets(input, sizeof(input), stdin);
        choice = strtol(input, NULL, 10);  // Convert to integer
        
        if (choice == 7) {
            break; // Exit loop if choice is 7
        }
        
        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                fgets(input, sizeof(input), stdin);
                value = strtol(input, NULL, 10);  // Convert input to integer
                
                stackPtr = push(stackPtr, value);
                printStack(stackPtr); // Print the stack nodes
                break;

            case 2:
                if (!isEmpty(stackPtr)) {
                    stackPtr = pop(stackPtr); // Pop node from stack
                } else {
                    puts("The Stack is Empty... Nothing to pop.");
                }
                printStack(stackPtr); // Print the current stack nodes
                break;

            case 3:
                if (!isEmpty(stackPtr)) {
                    topOfStack(stackPtr); // Print node at the top of the stack
                } else {
                    puts("The Stack is Empty.");
                }
                break;

            case 4:
                if (!isEmpty(stackPtr)) {
                    bottomOfStack(stackPtr); // Print node at the bottom of the stack
                } else {
                    puts("The Stack is Empty.");
                }
                break;

            case 5:
                printf("Enter an integer to search: ");
                fgets(input, sizeof(input), stdin);
                value = strtol(input, NULL, 10);  // Convert input to integer
                
                searchStack(stackPtr, value); // Search for a node in the stack
                break;

            case 6:
                printStack(stackPtr); // Print the entire stack
                break;

            default:
                printf("Invalid choice.\n\n");
                break;
        }
        
        instructions();
        printf("? ");
    }
    
    printf("End of run.\n");
    return 0;
}
