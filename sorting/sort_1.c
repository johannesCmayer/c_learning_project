#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populateArrayRandom( int *array, int ararySize );
void sort_1( int *array, int arraySize, int *passes );

enum weapons
{
laserGun,
machineGun,
spade,
};

#define PRINT_SORTED 0

int main()
{
  clock_t program_start_time = clock();

  srand(time(NULL));

  int arraySize = 10000;
  int data [arraySize];
  populateArrayRandom( &data[0], arraySize );
  int passes = 0;
  clock_t begin_sort_time = clock();
  sort_1( data, arraySize, &passes );
  clock_t end_sort_time = clock();

  if (PRINT_SORTED){
    for (size_t i = 0; i < arraySize; i++) {
      printf("%d\n", data[i]);
    }
  }
  printf("The sorting of the array with %d random integers took %f and %d passes were made over the data.\n",
    arraySize, (float)(end_sort_time - begin_sort_time) / CLOCKS_PER_SEC, passes);
  clock_t program_end_time = clock();
  printf("Total programm execution cpu time was %f\n", (float)(program_end_time - program_start_time) / CLOCKS_PER_SEC);
  return 0;
}

void populateArrayRandom( int *array, int arraySize )
{
  for ( int i = 0; i < arraySize; i++ ) {
    array[i] = rand();
  }
}

void sort_1( int *array, int arraySize, int *passes)
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
