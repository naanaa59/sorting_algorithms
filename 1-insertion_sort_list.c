#include "sort.h"


/**
 * swap_nodes - swaps nodes.
 * @list: the header of the list.
 * @node1: first node.
 * @node2: second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}
/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers in ascending order using the
 * Insertion sort algorithm.
 * @list: Head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				tmp = current->prev;
				print_list(*list);
				while (tmp && tmp->prev && (tmp->prev->n > tmp->n))
				{
					swap_nodes(list, tmp->prev, tmp);
					print_list(*list);
				}
				swapped = 1;
			}
			else
				current = current->next;
		}
	} while (swapped);
}
