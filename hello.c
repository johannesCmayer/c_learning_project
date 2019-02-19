#include <stdio.h>
#include <stdlib.h>

void ExtendArray(int *array, int access);
int DynFib(int num, int *numOfCalls, int *cache);
int Fib(int num, int *numOfCalls);

int DynFib(int num, int *numOfCalls, int *cache)
{
    if (cache[num] != 0)
    {
        return cache[num];
    }
    if (num < 0)
    {
        return 0;
    }   
    (*numOfCalls)++;
    int ret = 0;
    switch(num)
    {
        case 0:
            ret = 0;
        case 1:
            ret = 1;
        default:
            ret = DynFib (num-1, numOfCalls, cache) + DynFib (num-2, numOfCalls, cache);
    }
    ret = ret;
    (cache)[num] = ret;
    printf("Set %d to  %d \n", num, cache[num]);
    return ret;
}

int Fib(int num, int *numOfCalls)
{
    (*numOfCalls)++;
    switch(num)
    {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return Fib (num-1, numOfCalls) + Fib (num-2, numOfCalls);
    }
}

int GetArraySize(int *array)
{
    return sizeof(*array)/sizeof(int);
}

void ExtendArray(int *array, int access)
{
    const int extensionChunk = 100;
    int size = GetArraySize(array);
    printf("size of array is %d \n", size);
    if (size == 0)
    {
        printf("array has no memory, allocating now! \n");
        array = malloc(extensionChunk * sizeof(int));

    }
    if (size <= access)
    {
        array = realloc(array, extensionChunk * sizeof(int));
        printf("extended array to %d \n", GetArraySize(array));
    }
}

int main()
{
    int num = 0;
    char term;
    printf("Give Fibonacci itterations: ");
    if (scanf("%d%c", &num, &term) != 2 || term != '\n')
    {
        printf("You need to input a positive number! \n");
        return 1;
    }
    int numOfCalls = 0;   
    int numOfCalls2 = 0;
    int cache[num];
    for (int i = 0; i <= num; i++)
    {
        cache[i] = 0;
    }
    // wraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaap
    //printf("SIZE %lu \n", sizeof(cache)/sizeof(int));
    //printf("DynFib Result: %d \n", DynFib(num, &numOfCalls, cache));     
    //printf("Fib got called %d times \n", numOfCalls);
    printf("\n");
    printf("Fib Result: %d \n", Fib(num, &numOfCalls2));
    printf("Fib got called %d times \n", numOfCalls2);
    return 0;
}

