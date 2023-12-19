#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: our array to sort.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count_arr, *output_arr;

	if (!array || size < 2)
		return;
	count_arr = count(array, size);
	if (!count_arr)
		return;
	output_arr = output(array, size, count_arr);
	if (!output_arr)
	{
		free(count_arr);
		return;
	}
	free(count_arr);
	i = 0;
	while (i < size)
	{
		array[i] = output_arr[i];
		i++;
	}
	free(output_arr);
}
/**
 * get_max - Searches for max in array.
 * @array: Our array.
 * @size: size of array.
 * Return: maximum element in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * output - Creates a sorted array.
 * @array: Our array
 * @size: Size of the array.
 * @count: Array of coumpounded elements.
 * Return: sorted array.
 */
int *output(int *array, size_t size, int *count)
{
	int *output;
	size_t j;

	output = malloc(size * sizeof(int));
	if (!output)
		return (0);
	j = size - 1;
	while (1)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
		if (!j--)
			break;
	}
	return (output);
}
/**
 * count - Creates counting array to count
 * the elements or the array.
 * @array: array of integers.
 * @size: size of the array.
 * Return: counting array.
 */
int *count(int *array, size_t size)
{
	int *count;
	size_t i, count_len;

	count_len = get_max(array, size) + 1;
	count = malloc(count_len * sizeof(int));
	if (!count)
		return (0);
	i = 0;
	while (i < count_len)
		count[i++] = 0;
	i = 0;
	while (i < size)
		count[array[i++]]++;
	i = 0;
	while (++i < count_len)
		count[i] += count[i - 1];
	print_array(count, count_len);
	return (count);
}
