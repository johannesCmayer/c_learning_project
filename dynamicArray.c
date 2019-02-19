#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *array, int arrayLength);

int main()
{
    int arrayLength = 10;
    int array [arrayLength];
    for (int i = 0; i <= arrayLength; i++)
    {
        array[i] = i + 80;
    }

    PrintArray( array, arrayLength );
}

void PrintArray(int *array, int arrayLength)
{
    for (int i = 0; i <= arrayLength; i++)
    {
        printf("i element is %d \n", array[i]);
    }
}
