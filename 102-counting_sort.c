#include "sort.h"
/**
 * get_max - gets the max value in an array.
 * @array: the array.
 * @size: the zise of the array.
 * Return: max
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	while (size--)
	{
		if (array[size] > max)
			max = array[size];
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
	int j, *count, *output, max;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	output = malloc(sizeof(*output) * (max + 1));
	if (output == NULL)
	{
		free(output);
		return;
	}
	count = malloc(sizeof(*count) * size);
	if (count == NULL)
	{
		free(count);
		free(output);
		return;
	}
	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j < (max + 1); j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
