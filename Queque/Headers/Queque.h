#ifndef QUEQUE_H
#define QUEQUE_H

#define MAX_QUEQUE_SIZE 10

#include <stdlib.h>
#include <stdio.h>

struct node_t
{
    struct node_t *next;
    int value;
};

struct queque_t
{
    struct node_t *head;
    int actual_size;
};

void initQueque(struct queque_t *ptrQueque);
void addToQueque(struct queque_t *ptrQueque, int inputValue);
void pop(struct queque_t *ptrQueque);
void emptyQueque(struct queque_t *ptrQueque);
void printQueque(struct queque_t *ptrQueque); //prints from tail to head

#endif //QUEQUE_h