#include "../Headers/Queue.h"

void initQueue(struct queue_t *ptrQueue)
{
    ptrQueue->head = NULL;
    ptrQueue->actual_size = 0;
}

void addToQueue(struct queue_t *ptrQueue, int inputValue)
{
    if (ptrQueue->actual_size >= MAX_QUEUE_SIZE)
    {
        printf("Error! Max size of queue (%d) reached already, cannot add another element!\n", MAX_QUEUE_SIZE);
        return;
    }

    struct node_t *newNode = (struct node_t *)malloc(sizeof(struct node_t));
    ++ptrQueue->actual_size;
    newNode->value = inputValue;

    if (NULL == ptrQueue->head)
    {
        newNode->next = NULL;
        ptrQueue->head = newNode;
    }
    else
    {
        struct node_t *temp = ptrQueue->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void pop(struct queue_t *ptrQueue)
{
    if (NULL == ptrQueue->head)
    {
        puts("Cant empty pop element from empty queue!");
        return;
    }
    if (ptrQueue->actual_size <= 0)
    {
        ptrQueue->head = NULL;
    }
    else
    {
        struct node_t *temp = ptrQueue->head->next;
        free(ptrQueue->head);
        ptrQueue->head = temp;
        --ptrQueue->actual_size;
    }
}

void emptyQueue(struct queue_t *ptrQueue)
{
    while (ptrQueue->head)
    {
        pop(ptrQueue);
    }
}

void printQueue(struct queue_t *ptrQueue)
{
    struct node_t *temp = ptrQueue->head;

    for (int i = ptrQueue->actual_size - 1; i >= 0; --i)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    puts("");
}
