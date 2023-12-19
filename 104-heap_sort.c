#include "sort.h"
/**
 * sift_down - helper for the heap sort function
 * @array: array
 * @start: start
 * @end: end
 * @size: size
 */
void sift_down(int *array, size_t start, size_t end, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t swap = root;
	size_t child;
	int tmp;

	while (root * 2 + 1 <= end)
	{

		child = root * 2 + 1;
		if (array[swap] < array[child])
		{
			swap = child;
		}
		if (child + 1 <=  end && array[swap] < array[child + 1])
		{
			swap = child + 1;
		}
		if (swap == root)
		{
			return;
		}
		else
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, size);
			root = swap;
		}
	}
}
/**
 * heapify - helper for the heap sort function
 * @array: array
 * @size: size
 */
void heapify(int *array, size_t size);
void heapify(int *array, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start + 1 > 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}
/**
 * heap_sort - helper for the heap sort function
 * @array: array
 * @size: size
 */
void heap_sort(int *array, size_t size)
{

	size_t end;
	int tmp;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

