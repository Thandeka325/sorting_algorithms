#include "sort.h"
void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array,  size_t size);

/**
 * swap - Swaps two elements in an array
 * @a: First element.
 * @b: Second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using the lomuto patition scheme.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Total size of the array (for printing)
 *
 * Return: The index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size); }}}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts partitions of the array.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Total size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in an ascending order,
 * using Quick sort
 * @array: The array to be sorted.
 * @size: The size of the array
 */
void quick_sort(int *array,  size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
