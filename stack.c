#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int data;
  struct stack *ptr;
};

typedef struct stack Stack;

#include "stack.h"

// Run to test memory usage
int main()
{
  for (int i = 0; i < 2000; i++) {

    Stack **stack = create_stack();

    for (size_t j = 0; j < 200; j++) {
      push(stack, 42 + j);
    }

    while (!check_empty(stack)) {
      pop(stack);
    }

    destoy_stack(stack);

    printf("Stack run no %d\n", i);
  }
  printf("\n");
  return 0;
}

Stack **create_stack()
{
  Stack **root = calloc(1, sizeof(Stack *));
  *root = NULL;
  return root;
}

void destoy_stack(Stack **stack)
{
  while (!check_empty(stack)) {
    pop(stack);
  }
  free(stack);
}

void push(Stack **top, int x)
{
  Stack *node_ptr = malloc(sizeof(Stack));
  if (node_ptr)
  {
    node_ptr->data = x;
    node_ptr->ptr = *top;

    *top = node_ptr;
  }
  else
  {
    printf("ERROR allocation failed\n");
  }
}

int pop(Stack **top)
{
  int r = (**top).data;
  Stack *to_free = *top;
  *top = (**top).ptr;
  free(to_free);
  return r;
}

int check_empty(Stack **top)
{
  if (*top)
    return 0;
  else
    return 1;
}
