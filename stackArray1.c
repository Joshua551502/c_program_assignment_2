// include stack header file
#include "stackArray1.h"

int main(void)
{
   int value;
   StackTypePtr stackPtr = initStack();  // create & initialise stack
   
   /* read a series of values, push on stack, ensure stack non-full */
   printf("Enter A Series of Values, Zero to stop ");
   scanf("%d",&value);
   while(value != 0)
   {
     push(stackPtr, value);//add code here to push current value onto stack
     printf("Enter A Series of Values, Zero to stop ");
     scanf("%d",&value);
   } 
   
   // pop values and print, ensure stack is non-empty 
   puts("The values in the stack are: ");
  
   while(!isEmpty(stackPtr))/*ensure stack is not empty*/
   {
      //pop all values from stack and print
      printf("%d->", pop(stackPtr));
   }
   puts("");
   free(stackPtr);// releasing stack memory
   
}

