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
 * hoare_partition - divides array into two arrays
 * @array: the array
 * @low: lower index
 * @high: higher index
 * @size: array's size
 *
 * Return: index of partition
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pv = array[high];

	i = low;
	j = high;

	while (1)
	{
		while (array[i] < pv)
			i++;
		while (array[j] > pv)
			j--;
		if (i > j)
			return (j);
		if (i != j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		i++;
		j--;
	}
}

/**
 * quicksort_hoare_recursive - sorts using recursive quick sort
 * @array: our array
 * @low: low elem
 * @high: high elem
 * @size: array's size
 */
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pv_idx = hoare_partition(array, low, high, size);

		quicksort_hoare_recursive(array, low, pv_idx, size);
		quicksort_hoare_recursive(array, pv_idx + 1, high, size);
	}
}
/**
 * quick_sort_hoare - sorts an array of integers
 * in ascending order using the Quick sort
 * algorithm
 * @array: the array.
 * @size: array's size.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}
