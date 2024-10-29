#include "sort.h"

/**
 * swap - Swaps two elements in an array and prints the array.
 * @array: The array where elements will be swapped.
 * @a: The index of the first element.
 * @b: The index of the second element.
 * @size: The size of the array.
 */
void swap(int *array, size_t a, size_t b, size_t size)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;

	print_array(array, size);
}

/**
 * sift_down - Sifts down an element to maintain the max heap property.
 * @array: The array representing the heap.
 * @root: The index of the root element to sift down.
 * @end: The end index of the head.
 */
void sift_down(int *array, size_t root, size_t end)
{
	size_t child = 2 * root + 1;
	int temp = array[root];

	while (child <= end)
	{
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (temp >= array[child])
			break;
		array[root] = array[child];
		root = child;
		child = 2 * root + 1; }
	array[root] = temp;
}

/**
 * build_heap - Builds a max heap from the array.
 * @array: The array to build the heap from.
 * @size: The size of the array.
 */
void build_heap(int *array, size_t size)
{
	size_t i;

	for (i = (size / 2) - 1; i != (size_t)-1; i--)
		sift_down(array, i, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	build_heap(array, size);

	for (end = size - 1; end > 0; end--)
	{
		swap(array, 0, end, size);
		sift_down(array, 0, end - 1);
	}
}
