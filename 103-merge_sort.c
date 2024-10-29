#include "sort.h"

/**
 * merge - Merges two subarrays of array.
 * @array: Original array.
 * @temp: Temporary array for merging.
 * @left: Left start index.
 * @mid: Middle index.
 * @right: Right end index.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	while (i < mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++]; }
	while (i < mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];
	for (i = left; i <= right; i++)
		array[i] = temp[i];
	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid + 1);
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Helper function to implement recursion.
 * @array: Array to sort.
 * @temp: Temporary array for merging.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left >= right)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);

	merge(array, temp, left, mid + 1, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order,
 * using Merge sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);

	if (temp == NULL)
		return;
	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}
