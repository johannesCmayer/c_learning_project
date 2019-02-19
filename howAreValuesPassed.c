#include <stdio.h>

int doubleInt(int value);
int *incrementPointer(int *pointer);

int main()
{
  int a = 42;
  int *a_ptr = &a;

  a = doubleInt(a);
  incrementPointer(a_ptr);

  printf("%d and %p and %d\n", a, a_ptr, *manual_ptr);

  return 0;
}

int doubleInt(int value)
{
  return value * 2;
}

int *incrementPointer(int *pointer)
{
  return pointer+1;
}
