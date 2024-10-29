#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: Double pointer to the end of the list.
 * @left: Pointer to the left node to swap.
 * @right: Pointer to the right node to swap.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;

	if (!right->prev)
		*list = right;
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order,
 * using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		insert = current;
		while (insert->prev && insert->prev->n > insert->n)
		{
			swap_nodes(list, insert->prev, insert);
			print_list(*list);
		}
		current = current->next;
	}
}
