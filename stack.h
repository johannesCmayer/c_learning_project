#ifndef STACK_H_
#define STACK_H_

void push(Stack **top, int x);
int pop(Stack **top);
int check_empty(Stack **top);
Stack **create_stack();
void destoy_stack(Stack **stack);

#endif
