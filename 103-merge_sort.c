#include "sort.h"

/**
 * merge_compare - compare the left and right subarrays and then copy them
 *
 * @new: the array where th copy the result
 * @left: left subarrays
 * @right: right subarrays
 * @left_size: size of the lefts
 * @right_size: size of the rights
 */
void merge_compare(int *new, int *right, int *left,
			size_t left_size, size_t right_size);

void merge_compare(int *new, int *right, int *left,
			size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			new[k] = left[i];
			i++;
		}
		else
		{
			new[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		new[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		new[k] = right[j];
		j++;
		k++;
	}
}
/**
 *merge - merges the arrays after being sorted
 *
 * @array: the original array
 * @left: left subarray
 * @left_size: size of the left subarray
 * @right: right subarray
 * @right_size: the size of the right subarray
 */
void merge(int *array, int *left, int *right,
		size_t left_size, size_t right_size);
void merge(int *array, int *left, int *right,
		size_t left_size, size_t right_size)
{
	size_t i, j, m;
	int *new;

	new = malloc(sizeof(int) * (left_size + right_size));
	if (new == NULL)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < left_size; i++)
	{
		printf("%d", left[i]);
		if (i < left_size - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (j = 0; j < right_size; j++)
	{
		printf("%d", right[j]);
		if (j < right_size - 1)
			printf(", ");
	}
	printf("\n");

	merge_compare(new, right, left, left_size, right_size);

	printf("[Done]: ");
	for (m = 0; m < left_size + right_size; m++)
	{
		array[m] = new[m];
	}
	for (m = 0; m < left_size + right_size; m++)
	{
		printf("%d", array[m]);
		if (m < left_size + right_size - 1)
			printf(", ");
	}
	printf("\n");
	free(new);
}
/**
 * merge_sort - sorts an array of integers in ascending order using the
 * merge sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, right_size, left_size;
	int *left, *right;

	if (size > 1)
	{
		mid = size / 2;
		left = array;
		left_size = mid;
		right = array + mid;
		right_size = size - mid;
		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge(array, left, right, left_size, right_size);
	}
}
