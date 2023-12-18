#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: Our array.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int j, *count, *output, max = array[0];
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(output);
		return;
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(count);
		free(output);
		return;
	}
	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 1; j < (max + 1); j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
