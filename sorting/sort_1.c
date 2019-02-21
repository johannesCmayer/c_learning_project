#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "externVar.h"
#include "sort_1.h"


enum sortingFunctions
{
  laserGun,
  machineGun,
  spade,
};

int main()
{
  clock_t program_start_time = clock();

  int benchmarkArraySize = 1500;

  int flipsortPasses = 0;
  float sortTime_flip = benchmarkSorting( benchmarkArraySize, multipassFlipSort, &flipsortPasses );
  printf("The sorting of the array with %d random integers took %f and %d passes were made over the data.\n",
    benchmarkArraySize, sortTime_flip, flipsortPasses);

  int absoluteSortPasses = 0;
  float sortTime_absolutesort = benchmarkSorting( benchmarkArraySize, absoluteSort, &absoluteSortPasses );
  printf("The sorting of the array with %d random integers took %f and %d passes were made over the data.\n",
    benchmarkArraySize, sortTime_absolutesort, absoluteSortPasses);

  clock_t program_end_time = clock();
  printf("Total programm execution cpu time was %f\n", (float)(program_end_time - program_start_time) / CLOCKS_PER_SEC);

  return 0;
}

float benchmarkSorting( int arraySize, SORTING_FUNCTION sortingFunction, int *passes )
{
  int data [arraySize];
  populateArrayRandom( &data[0], arraySize );

  clock_t begin_sort_time = clock();
  sortingFunction( data, arraySize, passes );
  clock_t end_sort_time = clock();

  if (testIfSorted( &data[0], arraySize ))
    printf("Data is sorted\n");
  else
  {
    const int arrayEntriesToPrint = 10;
    printf("Data is NOT sorted. First %d array entrys are:\n", arrayEntriesToPrint);
    for (size_t i = 0; i < arraySize; i++)
    {
      printf("%d\n", data[i] );
      if (i > 20)
        break;
    }
  }
  return (float)(end_sort_time - begin_sort_time) / CLOCKS_PER_SEC;
}

void populateArrayRandom( int *array, int arraySize )
{
  srand(time(NULL));
  for ( int i = 0; i < arraySize; i++ ) {
    array[i] = rand();
  }
}

// Bubblesort
void multipassFlipSort( int *array, int arraySize, int *passes)
{
  int complete = 0;
  while (complete == 0)
  {
    complete = 1;
    for (size_t i = 0; i < arraySize - 1; i++)
    {
      if (passes)
        *passes += 1;
      // Flip elements if the first is larger
      if (array[i] > array[i+1])
      {
        int cache = array[i];
        array[i] = array[i+1];
        array[i+1] = cache;
        complete = 0;
      }
    }
  }
}

void mergeSort( int *array, int arraySize, int *passes)
{
  int sorted[arraySize];
  for (size_t i = 0; i < arraySize; i++) {
    if (array[i] > array[i + 1]){
      int cache = array[i];
      array[i] = array[i + 1];
      array[i + 1] = cache;
    }
  }
}

// INCOMPLETE
void cacheSort( int *array, int arraySize, int *passes)
{
  int smallestSorted[arraySize];
  int idx_sorted = 0;
  int nextIterArray[arraySize];
  int idx_next = 0;
  smallest = INT_MAX;

  for (size_t i = 0; i < arraySize; i++)
  {
    if (array[i] < smallest)
    {
      smallest = array[i];
      smallestSorted[idx_sorted++] = array[i];
    }
    else
    {
      nextIterArray[idx_next++] = array[i];
    }
  }
}

// Selection Sort
void absoluteSort( int *array, int arraySize, int *passes)
{
  for (size_t i = 0; i < arraySize; i++) {
    int smallest = INT_MAX;
    int smallestIdx = 0;
    for (size_t j = i; j < arraySize; j++) {
      if (array[j] < smallest) {
        smallest = array[j];
        smallestIdx = j;
      }
    }
    int cache = array[i];
    array[i] = smallest;
    array[smallestIdx] = cache;
  }
  *passes = arraySize;
}

// Selection Sort
void reversedAbsoluteSort( int *array, int arraySize, int *passes)
{
  for (size_t i = 0; i < arraySize; i++) {
    int biggest = 0;
    int biggestIdx = 0;
    for (size_t j = i; j < arraySize; j++) {
      if (array[j] > biggest) {
        biggest = array[j];
        biggestIdx = j;
      }
    }
    int cache = array[i];
    array[i] = biggest;
    array[biggestIdx] = cache;
  }
  reverseArray( array, arraySize );
  *passes = arraySize;
}

void reverseArray( int *array, int arraySize )
{
  int arrayCopy[arraySize];
  for (size_t i = 0; i < arraySize; i++) {
    arrayCopy[arraySize - 1 - i] = array[i];
  }
  for (size_t i = 0; i < arraySize; i++) {
    array[i] = arrayCopy[i];
  }
}

int testIfSorted( int *array, int arraySize )
{
  int previous = array[0];
  for (size_t i = 0; i < arraySize; i++) {
    if (array[i] < previous)
      return 0;
  }
  return 1;
}
