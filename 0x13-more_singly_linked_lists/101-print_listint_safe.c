#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: A pointer to the head of the listint_t linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *node;
    size_t count = 0;

    while (head != NULL)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;

        node = head;
        head = head->next;

        if (node <= head)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            exit(98);
        }
    }

    return (count);
}

