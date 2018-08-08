#include "../Headers/BinarySearchTree.h"

void initTree(struct node_t *treePtr)
{
    treePtr = NULL;
}

void addNode(struct node_t *treePtr, int inputValue)
{
    if (treePtr == NULL)
    {

        treePtr = malloc(sizeof(struct node_t));
        treePtr->data = inputValue;
        ++treePtr->count;
        treePtr->leftChild = NULL;
        treePtr->rightChild = NULL;
    }
    else
    {
        if (inputValue == treePtr->data)
        {
            ++treePtr->count;
        }
        else if (inputValue > treePtr->data)
        {
            addNode(treePtr->rightChild, inputValue);
        }
        else
        {
            addNode(treePtr->leftChild, inputValue);
        }
    }
}

void searchTree(struct node_t *treePtr, int inputValue)
{
    if (treePtr == NULL)
    {
        return;
    }
    if (inputValue == treePtr->data)
    {
        printf("%d was found , count: %d\n", inputValue, treePtr->count);
    }
    else if (inputValue > treePtr->data)
    {
        searchTree(treePtr->rightChild, inputValue);
    }
    else
    {
        searchTree(treePtr->leftChild, inputValue);
    }
}
