#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: The array.
 * @size: Array's size.
 */
void bitonic_sort(int *array, size_t size);
/**
 * bitonic_sort_recursive - orts an array of integers in
 * ascending with recursion.
 * @array: The array.
 * @start: first index
 * @len: length
 * @size: Array's size.
 * @order: order UP or DOWN
 */
void bitonic_sort_recursive(
		int *array, size_t start, size_t len, size_t size, int order);
/**
 * bitonic_sort_merge - merges two elements of the array.
 * @array: The array.
 * @start: first index
 * @len: length
 * @order: order UP or DOWN
 */
void bitonic_sort_merge(int *array, size_t start, size_t len, int order);

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: The array.
 * @size: Array's size.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_recursive(array, 0, size, size, 1);
}
/**
 * bitonic_sort_recursive - orts an array of integers in
 * ascending with recursion.
 * @array: The array.
 * @start: first index
 * @len: length
 * @size: Array's size.
 * @order: order UP or DOWN
 */
void bitonic_sort_recursive(
		int *array, size_t start, size_t len, size_t size, int order)
{
	size_t mid;

	if (len > 1)
	{
		mid = len / 2;

		printf("Merging [%lu/%lu] (%s):\n", len, size, order ? "UP" : "DOWN");
		print_array(&array[start], len);

		bitonic_sort_recursive(array, start, mid, size, 1);
		bitonic_sort_recursive(array, start + mid, mid, size, 0);

		bitonic_sort_merge(array, start, len, order);

		printf("Result [%lu/%lu] (%s):\n", len, size, order ? "UP" : "DOWN");
		print_array(&array[start], len);
	}
}
/**
 * bitonic_sort_merge - merges two elements of the array.
 * @array: The array.
 * @start: first index
 * @len: length
 * @order: order UP or DOWN
 */
void bitonic_sort_merge(int *array, size_t start, size_t len, int order)
{
	if (len > 1)
	{
		size_t mid = len / 2;
		size_t i, j;
		int tmp;

		for (i = start; i < start + mid; i++)
		{
			j = i + mid;
			if ((array[i] > array[j]) == order)
			{

				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
		bitonic_sort_merge(array, start, mid, order);
		bitonic_sort_merge(array, start + mid, mid, order);

	}
}
