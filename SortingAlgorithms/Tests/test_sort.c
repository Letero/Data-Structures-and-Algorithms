#include "../Headers/Sort.h"
#define SIZE 10
int array[SIZE] = {5, 4, 1, 6, 0, 3, 2, 9, 8, 7};

int main()
{
    int *sortedArray = bubbleSort(array);

    puts("Sorted array: ");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", sortedArray[i]);
    }
    puts("");

    return 0;
}