#include "../Headers/LinkedList.h"

void add_at_begin(struct node **head, const int inVal)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node *));
    newElement->val = inVal;
    newElement->next = *head;
    *head = newElement;
}

void push_back(struct node **head, const int inVal)
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
    puts(""); //new line
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

eError_t insert_at_pos(struct node **head, const int pos, const int inVal)
{
    struct node *newElement = NULL;
    struct node *temp = *head;
    eError_t retVal = E_OK;
    int iter = 0;

    if (pos == 0)
    {
        newElement = (struct node *)malloc(sizeof(struct node *));
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
                newElement = (struct node *)malloc(sizeof(struct node *));
                newElement->val = inVal;
                newElement->next = temp->next;
                temp->next = newElement;
                break;
            }
            ++iter;
            temp = temp->next;
        }
        if (iter > pos)
            retVal = OUT_OF_RANGE; // position out of range
    }
    return retVal; // successful
}

eError_t delete_at_pos(struct node **head, const int pos)
{
    struct node *temp = *head;
    struct node *current = NULL;
    int iter = 0;
    eError_t retVal = E_OK;
    if (pos == 0)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    else
    {
        while (temp)
        {
            if (NULL == temp->next) // if next element is null, it means that position is out of range
            {
            }
            else if (pos == iter)
            {
                current = temp->next->next;
                free(temp->next);
                temp->next = current;
                break;
            }
            ++iter;
            temp = temp->next;
        }
        if (iter > pos)
            retVal = OUT_OF_RANGE;
    }
    return retVal; // successful
}

eError_t pop_back(struct node **head)
{
    if (*head == NULL)
    {
        return INVALID_ARG_1; // empty list, cant remove any element
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return E_OK;
    }

    struct node *current = *head;
    struct node *temp;

    while (current->next)
    {
        temp = current;
        current = current->next;
    }

    free(current);
    current = temp;
    current->next = NULL;
    return E_OK;
}

eError_t delete_list(struct node **head)
{
    eError_t retVal = E_OK;
    if (NULL == *head)
    {
        retVal = EMPTY_LIST;
    }
    else
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
    return retVal;
}

void print_elem_at_Pos(struct node **head, const int pos)
{

    struct node *temp = *head;
    int count = 0;
    int flag = 0;
    while (temp)
    {
        if (count == pos)
        {
            printf("Element at position %d: %d\n", pos, temp->val);
            flag = 1;
            break;
        }
        temp = temp->next;
        ++count;
    }
    if (0 == flag)
    {
        printf("Position '%d' out of range!\n", pos);
    }
}