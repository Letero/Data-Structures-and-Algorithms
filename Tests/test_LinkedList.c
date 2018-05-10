#include "../Headers/LinkedList.h"

struct node *newList = NULL;

int main()
{
    add_at_begin(&newList, 5);
    push_back(&newList, 6);
    push_back(&newList, 7);
    push_back(&newList, 8);
    add_at_begin(&newList, 5);
    insert_at_pos(&newList, 0, 0);
    insert_at_pos(&newList, 6, 3);
    pop_back(&newList);
    print_list(&newList);
    delete_list(&newList);
    print_list(&newList);
}