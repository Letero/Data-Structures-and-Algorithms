#include "../Headers/Queque.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct queque_t newQueque;
    initQueque(&newQueque);
    addToQueque(&newQueque, 5);
    addToQueque(&newQueque, 6);
    addToQueque(&newQueque, 4);
    printQueque(&newQueque);
    deleteQueque(&newQueque);
    printQueque(&newQueque);
}