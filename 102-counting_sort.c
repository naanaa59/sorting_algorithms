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

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(count);
		return;
	}
	for (j = 0; j <= max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(output);
		return;
	}
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
