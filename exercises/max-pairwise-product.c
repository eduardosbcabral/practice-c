#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 7

int main()
{
  //int arraySize;

  //printf("Enter the array size: ");
  //scanf("%d", &arraySize);
  
  //int *numbers = (int *)malloc(sizeof(int) * arraySize); // dynamic memory allocation 

  int numbers[ARRAY_SIZE] = { 3, 6, 8, 2, 15, 13, 9 };

  int largestValuePosition, secondLargestValuePosition, maxPairWiseProduct;

  /*for (int i = 0; i < ARRAY_SIZE; i++) {
    scanf("%d", &numbers[i]);
  }*/

  largestValuePosition = 0;
  secondLargestValuePosition = 0;
  maxPairWiseProduct = 0;
  // arraySize = sizeof(numbers) / sizeof(numbers[0]); sizeOf: size of array in bytes
  // To determine the number of elements in the array, 
  // we can divide the total size of the array by the size of the array element. 
  // doesnt work when using malloc, because when we use dynamic allocation the array
  // is not on the stack.

  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (numbers[i] > numbers[largestValuePosition]) {
      largestValuePosition = i;
    }
  }

  for (int i = 0; i < ARRAY_SIZE; i++) {
    if(numbers[i] > numbers[secondLargestValuePosition] && i != largestValuePosition) {
      secondLargestValuePosition = i;
    }
  }

  maxPairWiseProduct = numbers[largestValuePosition] * numbers[secondLargestValuePosition];

  printf("Position: %d, second largest number: %d\n", secondLargestValuePosition, numbers[secondLargestValuePosition]);
  printf("Position: %d, largest number: %d\n", largestValuePosition, numbers[largestValuePosition]);
  printf("Max pairwise product: %d\n", maxPairWiseProduct);
}