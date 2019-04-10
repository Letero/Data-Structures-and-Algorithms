#include "../Headers/Queue.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct queue_t newQueue;
    initQueque(&newQueue);
    addToQueue(&newQueue, 1);
    addToQueue(&newQueue, 2);
    addToQueue(&newQueue, 3);
    addToQueue(&newQueue, 4);
    addToQueue(&newQueue, 5);
    addToQueue(&newQueue, 6);
    printQueue(&newQueue);
    emptyQueue(&newQueue);
    printQueue(&newQueue);
}