#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    size_t i;
    int *counting_array, *sorted_array;

    if (!array || size < 2)
        return;
    counting_array = create_counting_array(array, size);
    if (!counting_array)
        return;
    sorted_array = create_sorted_array(array, size, counting_array);
    if (!sorted_array)
    {
        free(counting_array);
        return;
    }
    free(counting_array);
    i = 0;
    while (i < size)
    {
        array[i] = sorted_array[i];
        i++;
    }
    free(sorted_array);
}

int *create_sorted_array(int *array, size_t size, int *counting_array)
{
    int *sorted_array;
    size_t i;

    sorted_array = malloc(size * sizeof(int));
    if (!sorted_array)
        return (0);

    i = size - 1;
    while (1)
    {
        sorted_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
        if (!i--)
            break;
    }

    return (sorted_array);
}

int *create_counting_array(int *array, size_t size)
{
    int *counting_array;
    size_t i, counting_array_len;

    counting_array_len = array_max(array, size) + 1;
    counting_array = malloc(counting_array_len * sizeof(int));
    if (!counting_array)
        return (0);

    i = 0;
    while (i < counting_array_len)
        counting_array[i++] = 0;

    i = 0;
    while (i < size)
        counting_array[array[i++]]++;

    i = 0;
    while (++i < counting_array_len)
        counting_array[i] += counting_array[i - 1];
    print_array(counting_array, counting_array_len);
    return (counting_array);
}

int array_max(int *array, size_t size)
{
    int max;
    size_t i;

    i = 0;
    max = array[0];
    while (i < size)
    {
        if (array[i] > max)
            max = array[i];
        ++i;
    }
    return (max);
}