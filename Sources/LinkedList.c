#include "../Headers/LinkedList.h"

void add_at_begin(struct node **head, int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    newElement->val = inVal;
    newElement->next = *head;
    *head = newElement;
}

void push_back(struct node **head, int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    newElement->val = inVal;
    newElement->next = NULL;
    if (NULL == *head)
    {
        *head = newElement;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next) // after this loop temp will point at the last element
        {
            temp = temp->next;
        }
        newElement->val = inVal;
        temp->next = newElement;
    }
}

void print_list(struct node **head)
{
    struct node *elem = *head;
    while (elem)
    {
        printf("%d", elem->val);
        elem = elem->next;
    }
}

unsigned int size_of_list(struct node **head)
{
    int counter = 0;
    struct node *temp = *head;
    while (temp)
    {
        ++counter;
        temp = temp->next;
    }
    return counter;
}

int insert_at_pos(struct node **head, int pos, int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    struct node *temp = *head;

    int iter = 0;

    if (pos == 0)
    {
        newElement->val = inVal;
        newElement->next = *head;
        *head = newElement;
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

int delete_at_pos(struct node **head, int pos)
{
}

int pop_back(struct node **head)
{
}

void delete_list(struct node **head)
{
    struct node *current = *head;
    struct node *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
}