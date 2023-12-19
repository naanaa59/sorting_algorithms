#include "sort.h"
#include <string.h>

/**
 * max - returns the max of an array
 * @array: the array of integers
 * @size: the size of the array
 *
 * Return: the max value
 */
int max(int *array, size_t size);
int max(int *array, size_t size)
{
	int _max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > _max)
		{
			_max = array[i];
		}
	}
	return (_max);
}
/**
 * count_sort -  helper for rasix_sort function
 * @array: array
 * @size: size
 * @exp: exp
 */
void count_sort(int *array, size_t size, int exp);
void count_sort(int *array, size_t size, int exp)
{
	size_t i;
	int j;
	const int radix = 10;
	int *output, *count;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	count = malloc(sizeof(int) * radix);
	if (count == NULL)
	{
		free(output);
		return;
	}
	memset(count, 0, radix * sizeof(int));

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % radix]++;
	}
	for (j = 1; j < radix; j++)
	{
		count[j] += count[j - 1];
	}

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % radix] - 1] = array[j];
		count[(array[j] / exp) % radix]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(output);
	free(count);
}
/**
 * radix_sort - sorts an array of positive integers
 * @array: array
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	int _max;
	int exp;

	_max = max(array, size);
	for (exp = 1; _max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);

		print_array(array, size);
	}
}

