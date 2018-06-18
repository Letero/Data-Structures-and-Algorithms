#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Common.h"

struct node
{
    int val;
    struct node *next;
};

void find_element_occurances(struct node **head, const int element);
void print_elem_at_Pos(struct node **head, const int pos);
eError_t delete_at_pos(struct node **head, const int pos);                  //delete node from a given position
eError_t delete_list(struct node **head);                                   //delete all elements of the list
eError_t insert_at_pos(struct node **head, const int pos, const int inVal); //insert value at a given position
eError_t pop_back(struct node **head);                                      //delete last element of the list
unsigned int size_of_list(struct node **head);                              //return number of elements in the list
void add_at_begin(struct node **head, const int inVal);                     //add new value to the list
void print_list(struct node **head);                                        //print all elements
void push_back(struct node **head, const int inVal);                        //add new value at the end of the list

#endif // LINKED_LIST_H
