#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int allocate_test( unsigned long long amount );

int main()
{
  printf("Trying to allocate %d * %d bytes\n", 1000000000, 300000);
  for (int i = 0; i < 200000; i++) {
    if (allocate_test(1000000000))
    {
      printf("Alloc of block %d failed, breaking\n", i);
      break;
    }
  }
  printf("Press enter to exit");
  getchar();
  return 0;
}

int allocate_test( unsigned long long amount )
{
  char *bytes;
  clock_t start = clock();
  bytes = malloc(amount);
  clock_t end = clock();
  float allocation_time = (float) (end - start) / CLOCKS_PER_SEC;

  if (bytes){
    return 0;
  }
  else
    return -1;
}
