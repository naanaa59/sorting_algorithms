#include "sort.h"

/**
 *  selection_sort -  sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: The array that we ll work with.
 * @size: Array's size
*/

void selection_sort(int *array, size_t size)
{
    size_t i, j, index;

    int min_val = 0;

    for (i = 0; i < size; i++)
    {
        index = i;
        min_val = array[i];
        for (j = i; j < size; j++)
        {
            if (array[j] < min_val)
            {
                min_val = array[j];
                index = j;
            }
        }
        array[index] = array[i];
        array[i] = min_val; 
    }
}