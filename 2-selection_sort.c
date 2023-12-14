#include "sort.h"

/**
 * insertion_sort_list - sorts by the marker of array
 * @list: dll, a listint type
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *ma = NULL;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;
	temp = *list;
	ma = *list;

	while (ma != NULL)
	{
		ma = ma->next;
		while (temp->prev && (temp->n < temp->prev->n))
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			temp->next->prev = temp;
			print_list(*list);
		}
		temp = ma;
	}
}
