#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Common.h"

struct node
{
    int val;
    struct node *next;
};

void add_at_begin(struct node **head, int inVal);          //add new value to the list
void push_back(struct node **head, int inVal);             //add new value at the end of the list
int insert_at_pos(struct node **head, int pos, int inVal); //insert value at a given position
int delete_at_pos(struct node **head, int pos);            //delete node from a given position
int pop_back(struct node **head);                          //delete last element of the list
unsigned int size_of_list(struct node **head);             //return number of elements in the list
void print_list(struct node **head);                       //print all elements
void delete_list(struct node **head);                      //delete all elements of the list

#endif // LINKED_LIST_H
