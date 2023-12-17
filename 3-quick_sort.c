#include "sort.h"
/**
 * swap - swaps two elems
 * @a: first elem
 * @b: second elem
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - divides array into two arrays
 * @array: the array
 * @low: lower index
 * @high: higher index
 * @size: array's size
 *
 * Return: index of partition
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pv = array[high];

	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pv)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts using recursive quick sort
 * @array: our array
 * @low: low elem
 * @high: high elem
 * @size: array's size
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pv_idx = partition(array, low, high, size);

		quicksort(array, low, pv_idx - 1, size);
		quicksort(array, pv_idx + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort
 * algorithm
 * @array: the array.
 * @size: array's size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
