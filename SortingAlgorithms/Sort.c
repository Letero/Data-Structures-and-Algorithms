#include "Sort.h"
#include <stdio.h>

void bubbleSort(int *arrayToSort, int size, int order)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (arrayToSort[i] > arrayToSort[j])
            {
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[j];
                arrayToSort[j] = temp;
            }
        }
    }
}

void selectionSort(int *arrayToSort, int size, int order)
{
    for (int i = 0; i < size; ++i)
    {
        int min = i;

        for (int j = i + 1; j < size; ++j)
        {
            if (arrayToSort[j] > arrayToSort[min])
            {
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[j];
                arrayToSort[j] = temp;
            }
        }
    }
}

void insertionSort(int *arrayToSort, int size, int order)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && arrayToSort[j - 1] > arrayToSort[j])
        {
            int tmp = arrayToSort[j];
            arrayToSort[j] = arrayToSort[j - 1];
            arrayToSort[j - 1] = tmp;
            j--;
        }
    }
}