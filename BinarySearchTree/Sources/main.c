#include "../Headers/BinarySearchTree.h"

int main(int argc, char *argv[])
{
    struct node_t *newBST = NULL;
    addNode(newBST, 5);
    addNode(newBST, 4);
    addNode(newBST, 3);
    searchTree(newBST, 4);
    return 0;
}