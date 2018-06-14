#include "../Headers/Queque.h"

void initQueque(struct queque_t *ptrQueque)
{
    ptrQueque->head = NULL;
    ptrQueque->actual_size = 0;
}

void addToQueque(struct queque_t *ptrQueque, int inputValue)
{
    if (ptrQueque->actual_size >= MAX_QUEQUE_SIZE)
    {
        printf("Error! Max size of queque (%d) reached already, cannot add another element!\n", MAX_QUEQUE_SIZE);
        return;
    }

    struct node_t *newNode = (struct node_t *)malloc(sizeof(struct node_t));
    ++ptrQueque->actual_size;
    newNode->value = inputValue;

    if (NULL == ptrQueque->head)
    {
        newNode->next = NULL;
        ptrQueque->head = newNode;
    }
    else
    {
        struct node_t *temp = ptrQueque->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void pop(struct queque_t *ptrQueque)
{
    if (NULL == ptrQueque->head)
    {
        puts("Cant empty pop element from empty queque!");
        return;
    }
    if (ptrQueque->actual_size <= 0)
    {
        ptrQueque->head = NULL;
    }
    else
    {
        struct node_t *temp = ptrQueque->head->next;
        free(ptrQueque->head);
        ptrQueque->head = temp;
        --ptrQueque->actual_size;
    }
}

void emptyQueque(struct queque_t *ptrQueque)
{
    while (ptrQueque->head)
    {
        pop(ptrQueque);
    }
}

void printQueque(struct queque_t *ptrQueque)
{
    struct node_t *temp = ptrQueque->head;

    for (int i = ptrQueque->actual_size - 1; i >= 0; --i)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    puts("");
}
