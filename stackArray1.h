// array implementation of a stack data structure
#include <stdio.h>
#include <stdlib.h>
#define MaxStack 10
#define EmptyValue -9999

// structure definition
typedef struct stackType{
  int top;
  int store[MaxStack];
}StackType, *StackTypePtr;

// function prototypes 

StackTypePtr initStack();
int isEmpty (StackTypePtr stackPtr);
int isFull (StackTypePtr stackPtr);
void push (StackTypePtr stackPtr, int value);
int pop (StackTypePtr stackPtr);
void top(StackTypePtr stackPtr);
void bottom(StackTypePtr stackPtr);

/*......Function Definitions..........*/

StackTypePtr initStack()
{
   StackTypePtr stackPtr; 		// Initialise pointer to Stack, stackPtr
   stackPtr = malloc(sizeof(StackType)); // Create memory for Stack
   if (stackPtr != NULL) 		// Initialise Stack;
   {
      stackPtr->top = -1;
   }else{
     puts ("Memory Issues... stack not created");
   }
   return stackPtr; 			// return pointer to Stack
   
}

int isEmpty (StackTypePtr stackPtr)
{
   // return true if top value == -1
   return stackPtr->top == -1;
}

int isFull (StackTypePtr stackPtr)
{
   // return true if top value == MaxStack - 1
   return stackPtr->top == MaxStack-1;
}


void push (StackTypePtr stackPtr, int value)
{
  if (isFull(stackPtr))/*check if stack is full*/
  {
     puts("Stack Overflow");
  }
  else{ /* Add code to insert value at the top-of-stack*/
        ++(stackPtr->top); 			// increment top value     
        stackPtr->store[stackPtr->top] = value;	// Place value at store[top]
  }
}

int pop (StackTypePtr stackPtr) 
{
   int popValue = 0;		// initialise variable to store popValue
   if(isEmpty(stackPtr))/*check if stack is empty before popping*/
   {
      puts("Stack is Empty");
      return EmptyValue; 	// return empty value;
   }
   else{ /* Add code to remove value from the top-of-stack */
         // preserve value at the top-of-stack store[top];
         popValue = stackPtr->store[stackPtr->top];
         --(stackPtr->top);		// decrement top
         return popValue;		// return value that was popped;
         
   }
}

void top(StackTypePtr stackPtr)
{
  if(isEmpty(stackPtr))
  {
     puts("Stack is Empty");
  }else{
     printf("Top of stack is %d\n", stackPtr->store[stackPtr->top]);
  }
  
}

void bottom(StackTypePtr stackPtr)
{
  if(isEmpty(stackPtr))
  {
     puts("Stack is Empty");
  }else{
     printf("Bottom of stack is %d\n", stackPtr->store[0]);
  }
  
}










