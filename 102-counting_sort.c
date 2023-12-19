#include "sort.h"
/**
 * get_max - gets the max value in an array.
 * @array: the array.
 * @size: the zise of the array.
 * Return: max
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
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
	int j, *count, *output;
	size_t i, count_range;

	if (array == NULL || size < 2)
		return;

	count_range = get_max(array, size) + 1;

	if (count_range < 2)
		return;

	count = calloc(count_range, sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i + 1 < count_range; j++)
		count[i + 1] += count[i];
	print_array(count, count_range);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
