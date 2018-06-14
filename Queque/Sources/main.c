#include "../Headers/Queque.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct queque_t newQueque;
    initQueque(&newQueque);
    addToQueque(&newQueque, 1);
    addToQueque(&newQueque, 2);
    addToQueque(&newQueque, 3);
    addToQueque(&newQueque, 4);
    addToQueque(&newQueque, 5);
    addToQueque(&newQueque, 6);
    printQueque(&newQueque);
    emptyQueque(&newQueque);
    printQueque(&newQueque);
}