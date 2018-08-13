#include "Sort.h"
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arrayToSort, int size, int order)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (arrayToSort[i] > arrayToSort[j])
            {
                swap(&arrayToSort[i], &arrayToSort[j]);
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
                swap(&arrayToSort[i], &arrayToSort[j]);
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
            swap(&arrayToSort[j], &arrayToSort[j - 1]);
            j--;
        }
    }
}

void mergeSort(int *arrayToSort, int size, int order)
{
}

void quickSort(int *arrayToSort, int size, int order)
{
}