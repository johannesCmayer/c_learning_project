#include <stdio.h>
#include <stdlib.h>

void ExtendArray(int *array, int access);
unsigned long long int DynFib(int num, int *numOfCalls, unsigned long long int *cache);
unsigned long long int Fib(int num, int *numOfCalls);

unsigned long long int DynFib(int num, int *numOfCalls, unsigned long long int *cache)
{
    if (cache[num] != 0)
    {
        return cache[num]
    }
    (*numOfCalls)++;
    int ret = 0;
    switch(num)
    {
        case 0:
            ret = (unsigned long long int) 0;
            break;
        case 1:
            ret = (unsigned long long int) 1;
            break;
        default: ;
            unsigned long long int f1 = DynFib (num-1, numOfCalls, cache);
            unsigned long long int f2 = DynFib (num-2, numOfCalls, cache);
            ret = f1 + f2;
            if (ret < f1 || ret < f2)
            {
                printf("Integer overflow detected, outputs are corrupted! \n");
            }
            break;
    }
    cache[num] = ret;
    return ret;
}

unsigned long long int Fib(int num, int *numOfCalls)
{
    (*numOfCalls)++;
    switch(num)
    {
        case 0:
            return (unsigned long long int) 0;
        case 1:
            return (unsigned long long int) 1;
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
    unsigned long long int cache[num];
    for (int i = 0; i <= num; i++)
    {
        cache[i] = 0;
    }
    //printf("SIZE %lu \n", sizeof(cache)/sizeof(int));
    printf("DynFib Result: %llu \n", DynFib(num, &numOfCalls, cache));
    printf("DynFib got called %d times \n", numOfCalls);
    /*
    printf("\n");
    printf("Fib Result: %llu \n", Fib(num, &numOfCalls2));
    printf("Fib got called %d times \n", numOfCalls2);
    */
    return 0;
}
