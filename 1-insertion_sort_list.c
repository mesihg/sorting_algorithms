#include "sort.h"

/**
 *swap_node - swap nodes
 *@h: pointer to head
 *@n1: first node to swap
 *@n2: second node to swap
 */

void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;

	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	(*n1)->prev = n2;
	(*n1) = n2->prev;
}
/**
 *insertion_sort_list - sort list of integers in ascending order
 *@list: pointer to list
 *Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *tmp, *insert;

	if (*list == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			swap_node(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
