
// array implementation of a stack data structure
#include <stdio.h>
#include <stdlib.h>
#define MaxStack 10
#define EmptyValue -9999

// structure definition
 typedef struct stackType {
   int top;
   int store[MaxStack];
} StackType, *StackTypePtr;
// function prototypes 

StackTypePtr initStack();
//int isEmpty (StackTypePtr stackPtr);
//int isFull (StackTypePtr stackPtr);
//void push (StackTypePtr stackPtr, int value);
//int pop (StackTypePtr stackPtr);



/*......Function Definitions..........*/

StackTypePtr initStack()
{
   // Initialise pointer to Stack, stackPtr
   // Create memory for Stack
   // Initialise Stack;
   // return pointer to Stack
   
}

int isEmpty (StackTypePtr stackPtr)
{
   // return true if top value == -1
   
}

int isFull (StackTypePtr stackPtr)
{
   // return true if top value == MaxStack - 1
   
}


void push (StackTypePtr stackPtr, int value)
{
  if (/*check if stack is full*/)
  {
     // inform user of "Stack Overflow"
  }
  else{ /* Add code to insert value at the top-of-stack*/
        // increment top value     
        // Place value at store[top]
  }
}

int pop (StackTypePtr stackPtr) 
{
   // initialise variable to store popValue
   if(/*check if stack is empty before popping*/)
   {
      // inform user "Stack is Empty"
      // return empty value;
   }
   else{ /* Add code to remove value from the top-of-stack */
         // preserve value at the top-of-stack store[top];
         // decrement top
         // return value that was popped;
         
   }
   
}












