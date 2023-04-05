#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp = head;
	const listint_t *prev = NULL;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	while (tmp != NULL)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		count++;

		if (tmp < tmp->next && prev != NULL)
			break;

		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp != NULL && tmp < tmp->next)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		count++;
	}

	return (count);
}
