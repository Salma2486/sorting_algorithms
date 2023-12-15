#include "sort.h"

/**
 * insertion_sort_list - sorts by the marker of array
 * @list: dll, a listint type
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *next, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;
			current->next = temp;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}

		current = next;
	}
}
