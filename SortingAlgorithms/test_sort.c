#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 20

int main()
{

    srand(time(0));
    int array[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = rand() % 100;
    }

    puts("Array before sorting: ");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }
    puts("");

    /*call sorting function*/
    selectionSort(array, SIZE, 0);

    puts("Sorted array: ");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }
    puts("");

    return 0;
}