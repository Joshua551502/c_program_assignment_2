#include <stdio.h>
#include "stackArray.h"

int main(void) {
    int id;
    char name[20];
    float mark;
    char code;

    // Create & initialize stack
    StackTypePtr stackPtr = initStack();

    // Read a series of ids, push on stack, ensure stack non-full
    printf("Enter ID, NAME, MARK, CODE, 0 to stop: ");
    scanf("%d%19s%f %c", &id, name, &mark, &code);
    while (id != 0) {
        // Push current student onto stack
        push(stackPtr, id, name, mark, code);
        printf("Enter ID, NAME, MARK, CODE, 0 to stop: ");
        scanf("%d%19s%f %c", &id, name, &mark, &code);
    }

    // Pop ids and print, ensure stack is non-empty
    puts("The ids in the stack are:");
    while (!isEmpty(stackPtr)) { // Ensure stack is not empty
        Student any = pop(stackPtr); // Pop all ids from stack and print
        printf("%d %s %.2f %c\n", any.sId, any.sName, any.sMark, any.sCode);
    }
    puts("");

    // Release stack memory
    free(stackPtr);

    return 0;
}
