#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t size = 0;
    listint_t *temp, *prev;

    if (h == NULL || *h == NULL)
        return (size);

    temp = *h;
    prev = NULL;

    while (temp != NULL)
    {
        size++;
        if (temp < temp->next && prev != NULL)
            prev->next = NULL;
        else
            prev = temp;
        temp = temp->next;
        free(prev);
    }

    *h = NULL;

    return (size);
}

