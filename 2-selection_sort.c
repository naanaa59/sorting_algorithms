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

	int min_val, flag = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		index = i;
		flag = 0;
		min_val = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min_val)
			{
				min_val = array[j];
				index = j;
			}
			if (array[j] < array[j - 1])
			{
				flag = 1;
			}
		}
		if (flag == 0)
			break;
		array[index] = array[i];
		array[i] = min_val;
		if (i != index)
			print_array(array, size);
	}
}
