#include "sort.h"
/**
 * get_max - gets the max value in an array.
 * @array: Our array.
 * @size: size of the array.
 * Return: the maximum.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: Our array.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, j, *count, *output, max = array[0];

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
