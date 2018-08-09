#include "Sort.h"

int *bubbleSort(int *arrayToSort, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (arrayToSort[i] < arrayToSort[j])
            {
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[j];
                arrayToSort[j] = temp;
            }
            else
            {
                continue;
            }
        }
    }
    return arrayToSort;
}