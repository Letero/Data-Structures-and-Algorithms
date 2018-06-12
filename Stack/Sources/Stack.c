#include "../Headers/Stack.h"

#include <stdio.h>

void push(struct stack_t *stackPtr, int elem)
{
    if (stackPtr->top >= MAX_STACK_SIZE)
    {
        printf("Stack is full, size : %d\n", MAX_STACK_SIZE);
    }
    else
    {
        stackPtr->stackStorage[stackPtr->top++] = elem;
    }
}

void pop(struct stack_t *stackPtr)
{
    if (isEmpty(stackPtr))
    {
        puts("Can't pop element from an empty stack!");
    }
    else
    {
        --stackPtr->top;
    }
}

void printStack(struct stack_t *stackPtr)
{
    if (isEmpty(stackPtr))
    {
        puts("Error in function printStack(): Stack is empty");
    }
    else
    {
        puts("TOP");
        for (int i = stackPtr->top; i >= 0; --i)
        {
            printf("%d\n", stackPtr->stackStorage[i]);
        }
        puts("BOTTOM");
    }
}

void top(struct stack_t *stackPtr) // print top element of the stack
{
    if (isEmpty(stackPtr))
    {
        puts("Error in function top(): Stack is empty");
    }
    else
    {
        printf("Value at the top of the stack is %d. \n", stackPtr->stackStorage[--stackPtr->top]);
    }
}

int isEmpty(struct stack_t *stackPtr) // return 1 if empty, otherwise 0
{
    if (stackPtr->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void stackInit(struct stack_t *stackPtr)
{
    stackPtr->top = 0;
}

void emptyStack(struct stack_t *stackPtr)
{
    stackPtr->top = 0;
}