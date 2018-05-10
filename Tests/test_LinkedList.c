#include "../Headers/LinkedList.h"
struct node *head;
int main()
{
    add_at_begin(5);
    push_back(6);
    push_back(7);
    push_back(8);
    add_at_begin(5);
    insert_at_pos(0, 0);
    insert_at_pos(6, 3);
    delete_list();
    print_list();
}