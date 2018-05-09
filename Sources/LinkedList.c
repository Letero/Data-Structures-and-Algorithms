#include "../Headers/LinkedList.h"

void add_at_begin(int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    newElement->val = inVal;
    newElement->next = head;
    head = newElement;
}

void push_back(int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    newElement->val = inVal;
    newElement->next = NULL;
    if (NULL == head)
    {
        head = newElement;
    }
    else
    {
        struct node *temp = head;
        while (temp->next) // after this loop temp will be set at last element
        {
            temp = temp->next;
        }
        newElement->val = inVal;
        temp->next = newElement;
    }
}

void print_list()
{
    struct node *elem = head;
    while (elem)
    {
        printf("%d", elem->val);
        elem = elem->next;
    }
}

unsigned int size_of_list()
{
    int counter = 0;
    struct node *temp = head;
    while (temp)
    {
        ++counter;
        temp = temp->next;
    }
    return counter;
}

int insert_at_pos(int pos, int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    struct node *temp = head;

    int iter = 0;

    if (pos == 0)
    {
        newElement->val = inVal;
        newElement->next = head;
        head = newElement;
    }
    else
    {
        while (temp)
        {
            if (pos - 1 == iter)
            {
                newElement->val = inVal;
                newElement->next = temp->next;
                temp->next = newElement;
                break;
            }
            ++iter;
            temp = temp->next;
        }
        return -1; // position out of range
    }
    return 0; // successful
}