#ifndef QUEQUE_H
#define QUEQUE_H

struct node_t
{
    int value;
    struct node_t *prev;
};

struct queque_t
{
    struct node_t *head;
    struct node_t *tail;
    int size;
    int limit;
};

void initQueque(struct queque_t *quequePtr, int limit); //set limit, pointers and size

#endif //QUEQUE_h