#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct stackNode {
	int data;
	struct stackNode *nextPtr;
};
// Type renaming using typedef
typedef struct stackNode StackNode;
typedef struct stackNode *StackNodePtr;

/* Function Prototypes */
StackNodePtr push(StackNodePtr topPtr, int info);
StackNodePtr pop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void topOfStack(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void bottomOfStack(StackNodePtr topPtr);
void searchStack(StackNodePtr topPtr, int key);
void instructions(void);

/* Function Definitions */
StackNodePtr push(StackNodePtr topPtr, int info) {
	// Initialise pointer for new StackNode
	StackNodePtr newPtr = malloc(sizeof(StackNode));
	
	// Push new StackNode onto top-of-stack
	if(newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = topPtr;
		topPtr = newPtr;
	} else {
		printf("%d not inserted. No memory available.\n", info);
	}
	return topPtr; // return pointer to top-of-stack
}

StackNodePtr pop(StackNodePtr topPtr) {
	// Initialise temporary pointer to hold address of StackNode to pop
	StackNodePtr tempPtr = topPtr;
	
	// Pop StackNode from the top-of-stack
	if(tempPtr != NULL) {
		printf("%d deleted\n", tempPtr->data);
		topPtr = topPtr->nextPtr;
		free(tempPtr);
	}
	return topPtr; // return pointer to top-of-stack
}

void printStack(StackNodePtr topPtr) {
	StackNodePtr currentPtr = topPtr;
	if(currentPtr == NULL) {
		puts("The stack is empty");
	} else {
		printf("The stack is:\n");
		while(currentPtr != NULL) {
			printf("%d <- ", currentPtr->data); // print current node
			currentPtr = currentPtr->nextPtr; // move to the next node
		}
		printf("NULL\n\n");
	}
}

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

void topOfStack(StackNodePtr topPtr) {
	if(topPtr != NULL) {
		printf("%d is at top-of-stack\n", topPtr->data);
	}
}

void instructions(void) {
	printf("Enter choice:\n");
	printf("1 to push a value on the stack\n");
	printf("2 to pop a value off the stack\n");
	printf("3 to display the top of the stack\n");
	printf("4 to display the bottom of the stack\n");
	printf("5 to search for a value in the stack\n");
	printf("6 to print the entire stack\n");
	printf("7 to end the program\n");
}

void bottomOfStack(StackNodePtr topPtr) {
	StackNodePtr currentPtr = topPtr;
	while(currentPtr != NULL && currentPtr->nextPtr != NULL) {
		currentPtr = currentPtr->nextPtr;
	}
	if(currentPtr != NULL) {
		printf("%d is at bottom-of-stack\n", currentPtr->data);
	}
}

void searchStack(StackNodePtr topPtr, int key) {
	StackNodePtr currentPtr = topPtr;
	int position = 0;
	while(currentPtr != NULL && key != currentPtr->data) {
		currentPtr = currentPtr->nextPtr;
		position++;
	}
	if(currentPtr == NULL) {
		printf("%d not found\n", key);
	} else {
		printf("%d found at location %d\n", key, position + 1);
	}
}
