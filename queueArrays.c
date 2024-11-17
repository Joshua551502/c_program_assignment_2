// Queue implemented using an array
#include "queueArrays.h"

int main(void)
{
  // define Queue Pointer & Initialize Queue
  QueueTypePtr qPtr = initQueue();
  
  int value; 
  printf("Enter some values, zero to quit ");
  scanf("%d",&value);
  while(value != 0)
  {
     enqueue(qPtr, value);
     printf("Enter some values, zero to quit ");
     scanf("%d",&value);
  }
  puts("The values in the queue are: ");
  while(!(isEmpty(qPtr)))
  {
    printf("%d ", dequeue(qPtr));

  }
  puts("");
  free(qPtr);
}




