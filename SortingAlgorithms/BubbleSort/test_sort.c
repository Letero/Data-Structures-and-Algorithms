#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10
int array[SIZE] = {5, 4, 1, 6, 0, 3, 2, 9, 8, 7};

int main()
{

    puts("Array before sorting: ");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }

    int *sortedArray = bubbleSort(array, SIZE);

    puts("Sorted array: ");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", sortedArray[i]);
    }
    puts("");

    free(sortedArray);
    return 0;
}