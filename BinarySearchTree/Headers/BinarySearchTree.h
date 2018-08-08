#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    int data;
    int count;
    struct node_t *leftChild;
    struct node_t *rightChild;
};

void addNode(struct node_t *treePtr, int inputValue);
void initTree(struct node_t *treePtr);
void printTree(struct node_t *treePtr);
void searchTree(struct node_t *treePtr, int inputValue);

#endif //BINARYSEARCHTREE_H