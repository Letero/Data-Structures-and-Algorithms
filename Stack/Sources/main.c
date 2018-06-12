#include "../Headers/Stack.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stack_t newStack;

    stackInit(&newStack);
    push(&newStack, 0);
    push(&newStack, 1);
    push(&newStack, 2);
    push(&newStack, 3);
    push(&newStack, 4);
    push(&newStack, 0);
    push(&newStack, 1);
    push(&newStack, 2);
    push(&newStack, 3);
    push(&newStack, 4);
    pop(&newStack);
    pop(&newStack);
    push(&newStack, 10);
    top(&newStack);
    printStack(&newStack);
}