#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 10

#include <stdlib.h>
#include <stdio.h>

struct node_t
{
    struct node_t *next;
    int value;
};

struct queue_t
{
    struct node_t *head;
    int actual_size;
};

void initQueue(struct queue_t *ptrQueue);
void addToQueue(struct queue_t *ptrQueue, int inputValue);
void pop(struct queue_t *ptrQueue);
void emptyQueue(struct queue_t *ptrQueue);
void printQueue(struct queue_t *ptrQueue); //prints from tail to head

#endif //QUEUE_H