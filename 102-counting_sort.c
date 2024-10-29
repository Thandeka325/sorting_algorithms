#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order,
 * using Counting algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = 0;
	int *count, *output;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc((max + 1) * sizeof(int));

	if (!count)
		return;
	output = malloc(size * sizeof(int));

	if (!output)
	{
		free(count);
		return; }
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--; }
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
