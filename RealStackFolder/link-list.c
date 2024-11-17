#include "link-list.h"

int main(void) {
    // Create stack pointer
    ItemPtr stackPtr = NULL;

    int choice;
    char input[10];  // Buffer for storing user input

    stackMenu();
    printf("");

    while (true) {
        fgets(input, sizeof(input), stdin);
        choice = strtol(input, NULL, 10);  // Convert to integer
        
        if (choice == 6) {  // Updated exit condition
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
                printf("Enter Item ID: ");
                char *id = validString();
                printf("Enter Item Name: ");
                char *name = validString();
                printf("Enter Condition (N/U/R): ");
                char condition = getchar();
                getchar();  // Consume newline character after condition input
                printf("Enter Price: ");
                float price = validNumericValue();

                stackPtr = push(stackPtr, id, name, condition, price);
                printStack(stackPtr); // Print the stack nodes
                free(id);
                free(name);
                break;

            case 4:
                if (!isEmpty(stackPtr)) {
                    stackPtr = pop(&stackPtr); // Pop node from stack
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
