#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 10

struct stack_t
{
    int stackStorage[MAX_STACK_SIZE];
    int top;
};

void stackInit(struct stack_t *stackPtr);
void emptyStack(struct stack_t *stackPtr);
void push(struct stack_t *stackPtr, int elem);
void pop(struct stack_t *stackPtr);
void top(struct stack_t *stackPtr);    // print top element of the stack
int isEmpty(struct stack_t *stackPtr); // return 1 if empty, otherwise 0
void printStack(struct stack_t *stackPtr);

#endif //STACK_H