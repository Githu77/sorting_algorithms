#include "sort.h"

/**
* insertion_sort_list - uses swapping of elements to sort them
* @list: input list to sort
*
*
*
*
*
*
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *point, *nt;

	if (list && *list && (*list)->next)
	{
		tmp = (*list)->next;
		point = tmp->prev;
		nt = tmp->next;

		while (tmp)
		{
			if (tmp->n < point->n)
			{
				swap_list(point, tmp, nt, list);
			}
			tmp = nt;
			if (tmp)
			{
				nt = tmp->next;
				point = tmp->prev;
			}
		}
	}
}

/**
* swap_list - swaps the position of two nodes in a linked list
* @point: previous node
* @tmp: temp
* @nt: next node
* @h: head of list
*
*
*
*
*
*/
void swap_list(listint_t *point, listint_t *tmp, listint_t *nt, listint_t **h)
{

	while (point && tmp->n < point->n)
	{
		if (nt)
			nt->prev = point;
		tmp->next = point;
		tmp->prev = point->prev;
		if (point->prev)
			(point->prev)->next = tmp;
		point->prev = tmp;
		point->next = nt;
		nt = point;
		point = tmp->prev;
		if ((*h)->prev)
			*h = (*h)->prev;
		print_list(*h);
	}
}
