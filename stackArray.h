// array implementation of a stack data structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxStack 10
#define EmptyValue -9999

typedef struct student {
   int sId;
   char sName[20];
   float sMark;
   char sCode;
} Student;

// structure definition
typedef struct stackType {
  int top;
  Student store[MaxStack]; // Change store to hold Student structures
} StackType, *StackTypePtr;

// function prototypes
StackTypePtr initStack();
int isEmpty(StackTypePtr stackPtr);
int isFull(StackTypePtr stackPtr);
void push(StackTypePtr stackPtr, int id, char name[20], float mark, char code);
Student pop(StackTypePtr stackPtr);
void top(StackTypePtr stackPtr);
void bottom(StackTypePtr stackPtr);

/*......Function Definitions..........*/

StackTypePtr initStack() {
   StackTypePtr stackPtr; // Initialise pointer to Stack, stackPtr
   stackPtr = malloc(sizeof(StackType)); // Create memory for Stack
   if (stackPtr != NULL) { // Initialise Stack
      stackPtr->top = -1;
   } else {
      puts("Memory Issues... stack not created");
   }
   return stackPtr; // return pointer to Stack
}

int isEmpty(StackTypePtr stackPtr) {
   return stackPtr->top == -1; // Return true if top value == -1
}

int isFull(StackTypePtr stackPtr) {
   return stackPtr->top == MaxStack - 1; // Return true if top value == MaxStack - 1
}

void push(StackTypePtr stackPtr, int id, char name[20], float mark, char code) {
  if (isFull(stackPtr)) { // Check if stack is full
     puts("Stack Overflow");
  } else {
     ++(stackPtr->top); // Increment top value     
     stackPtr->store[stackPtr->top].sId = id; // Set id
     strcpy(stackPtr->store[stackPtr->top].sName, name); // Set name
     stackPtr->store[stackPtr->top].sMark = mark; // Set mark
     stackPtr->store[stackPtr->top].sCode = code; // Set code
  }
}

Student pop(StackTypePtr stackPtr) {
   Student popStudent = {0, "", 0.0, ' '}; // Initialise variable to store popValue
   if (isEmpty(stackPtr)) { // Check if stack is empty before popping
      puts("Stack is Empty");
      return popStudent; // Return empty value
   } else {
      popStudent = stackPtr->store[stackPtr->top]; // Preserve value at the top of the stack
      --(stackPtr->top); // Decrement top
      return popStudent; // Return value that was popped
   }
}

void top(StackTypePtr stackPtr) {
  if (isEmpty(stackPtr)) {
     puts("Stack is Empty");
  } else {
     printf("Top of stack is %d %s %.2f %c\n", 
             stackPtr->store[stackPtr->top].sId,
             stackPtr->store[stackPtr->top].sName,
             stackPtr->store[stackPtr->top].sMark,
             stackPtr->store[stackPtr->top].sCode);
  }
}

void bottom(StackTypePtr stackPtr) {
  if (isEmpty(stackPtr)) {
     puts("Stack is Empty");
  } else {
     printf("Bottom of stack is %d %s %.2f %c\n", 
             stackPtr->store[0].sId,
             stackPtr->store[0].sName,
             stackPtr->store[0].sMark,
             stackPtr->store[0].sCode);
  }
}
