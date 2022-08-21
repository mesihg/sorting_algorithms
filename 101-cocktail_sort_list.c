#include "sort.h"

/**
 * swap_forward - swap node from left to right
 * @list: pointer to list
 * @head: pointer to head of the list
 * @curr: current node to be swapped
 * Return: void
 */

void swap_forward(listint_t **list, listint_t *head, listint_t *curr)
{
	if (head->prev)
		head->prev->next = curr;
	else
		*list = curr;
	if (curr->next)
		curr->next->prev = head;
	head->next = curr->next;
	curr->prev = head->prev;
	curr->next = head;
	head->prev = curr;
	print_list(*list);

}

/**
 * swap_backward - swap node from right to left
 * @list: pointer to list
 * @head: pointer to the head of the list
 * @curr: pointer to the current node to be swapped
 * Return: void
 */

void swap_backward(listint_t **list, listint_t *head, listint_t *curr)
{
	curr = head->prev;
	curr->next->prev = curr->prev;
	if (curr->prev)
		curr->prev->next = curr->next;
	else
		*list = curr->next;
	curr->prev = curr->next;
	curr->next = curr->next->next;
	curr->prev->next = curr;
	if (curr->next)
		curr->next->prev = curr;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: pointer to list of listint_t struct
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *curr;
	int flag = 1;

	if (list)
	{
		head = *list;
		while (flag != 0)
		{
			flag = 0;
			while (head->next)
			{
				if (head->n > head->next->n)
				{
					curr = head->next;
					swap_forward(list, head, curr);
					flag = 1;
				}
				else
					head = head->next;
			}
			if (flag == 0)
				break;
			flag = 0;
			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swap_backward(list, head, curr);
					flag = 1;
				}
				else
					head = head->prev;
			}

		}
	}
}
