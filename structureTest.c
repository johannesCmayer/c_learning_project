#include <string.h>
#include <stdio.h>



struct Person{
  char firstName[50];
  char lastName[50];
};

struct LongInt{
  unsigned int manyBits : 4;
  unsigned int manyBits2 : 4;
};

void mutatePerson( struct Person *person );

int main()
{
  struct LongInt thisIsLong;
  thisIsLong.manyBits = 0;
  thisIsLong.manyBits2 = 0;
  for (size_t i = 0; i < 129; i++) {
    thisIsLong.manyBits = i;
    printf("The value is %d | %d\n", thisIsLong.manyBits, thisIsLong.manyBits2);
  }
  return 0;
}

void stringStuff()
{
  struct Person person_1;
  strcpy(person_1.firstName, "Johannes");
  strcpy(person_1.lastName, "Mayer");

  mutatePerson( &person_1 );

  printf("Hello %s %s\n", person_1.firstName, person_1.lastName);
}

void mutatePerson( struct Person *person )
{
  strcpy(person->firstName, "Dick");

  printf("Hello %s %s\n", person->firstName, person->lastName);
}
