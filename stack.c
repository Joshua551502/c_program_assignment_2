#include "stack.h"

int main(void) {
    // Create stack pointer
    StackNodePtr stackPtr = NULL;

    int choice;
    int value;

    stackMenu();
    printf("? ");
    
    // Using fgets instead of scanf for input
    char input[10];  // Buffer for storing user input
    
    // Read and process user input until choice is 6 (exit)
    while (true) {
        fgets(input, sizeof(input), stdin);
        choice = strtol(input, NULL, 10);  // Convert to integer
        
        if (choice == 6) {
            break; // Exit loop if choice is 6
        }
        
        switch (choice) {
            case 1:
                if (!isEmpty(stackPtr)) {
                    topOfStack(stackPtr); // Print node at the top of the stack
                } else {
                    puts("The Stack is Empty.");
                }
                break;

            case 2:
                if (!isEmpty(stackPtr)) {
                    bottomOfStack(stackPtr); // Print node at the bottom of the stack
                } else {
                    puts("The Stack is Empty.");
                }
                break;

            case 3:
                printf("Enter an integer: ");
                fgets(input, sizeof(input), stdin);
                value = strtol(input, NULL, 10);  // Convert input to integer
                
                stackPtr = push(stackPtr, value);
                printStack(stackPtr); // Print the stack nodes
                break;

            case 4:
                if (!isEmpty(stackPtr)) {
                    ItemPtr poppedItem = pop(&stackPtr); // Pop node from stack
                    free(poppedItem); // Free memory of popped item
                } else {
                    puts("The Stack is Empty... Nothing to pop.");
                }
                printStack(stackPtr); // Print the current stack nodes
                break;

            case 5:
                printStack(stackPtr); // Print the entire stack
                break;

            default:
                printf("Invalid choice.\n\n");
                break;
        }
        
        stackMenu();
        printf("? ");
    }
    
    printf("End of run.\n");
    return 0;
}
