#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Common.h"

struct node
{
    int val;
    struct node *next;
};

struct node *head;

void add_at_begin(int inVal);          //add new value to the list
void push_back(int inVal);             //add new value at the end of the list
int insert_at_pos(int pos, int inVal); //insert value at a given position
void delete_at_pos(int pos);           //delete node from a given position
void pop_back();                       //delete last element of the list
unsigned int size_of_list();           //return number of elements in the list
void print_list();                     //print all elements

#endif // LINKED_LIST_H
