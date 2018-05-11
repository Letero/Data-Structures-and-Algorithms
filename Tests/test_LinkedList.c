#include "../Headers/LinkedList.h"
#include "../Headers/Test.h"

struct node *newList = NULL;

int main()
{
    add_at_begin(&newList, 5);
    add_at_begin(&newList, 5);
    push_back(&newList, 6);
    push_back(&newList, 7);
    push_back(&newList, 8);
    add_at_begin(&newList, 5);
    TEST(insert_at_pos(&newList, 0, 0), "insert_at_pos");
    TEST(insert_at_pos(&newList, 6, 0), "insert_at_pos");
    pop_back(&newList);
    TEST(delete_at_pos(&newList, 6), "delete_at_pos");
    //  print_list(&newList);
    TEST(delete_list(&newList), "delete_list");
    TEST(delete_list(&newList), "delete_list");
}