#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int data;
  struct stack *ptr;
}

typedef struct stack Stack;
typedef Stack *stackPtr;

int main()
{
  Stack *stack = Stack;

  return 0;
}

void push(stackPtr *top, int x)
{
  Stack *node_ptr = malloc(sizeof(Stack));
  if (node_ptr)
  {
    node_ptr->data = x;
    node_ptr->ptr = *top;
    *top = node_ptr;
  }
}

int pop(stackPtr *top)
{

}

int checkEmpty(stackPtr *top)
{

}
