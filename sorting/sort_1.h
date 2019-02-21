#ifndef SORT_1_H_
#define SORT_1_H_

/// Put random integers into an ineger array
void populateArrayRandom( int *array, int ararySize );
/// Sort an integer array by flipping positions in an array if the first element is bigger
void multipassFlipSort( int *array, int arraySize, int *passes );
/// Sequentialy scan the array for the smallest not yet sorted number and append it to the sorted numbers
void reversedAbsoluteSort( int *array, int arraySize, int *passes);
void absoluteSort( int *array, int arraySize, int *passes);
/// Return 1 if data is sorted asendingly, 0 otherwise
int testIfSorted( int *array, int arraySize );
void reverseArray( int *array, int arraySize );

typedef void (*SORTING_FUNCTION)(int *, int, int *);
float benchmarkSorting( int arraySize, SORTING_FUNCTION sortingFunction, int *passes );

#endif
