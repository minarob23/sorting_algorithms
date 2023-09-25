#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion sort
 *
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *sorted, *temp;

    current = (*list)->next;

    while (current)
    {
        sorted = current->prev;

        while (sorted && sorted->n > current->n)
        {
            temp = sorted->prev;

            if (sorted->next)
                sorted->next->prev = sorted;

            sorted->next = current->next;
            current->prev = sorted->prev;
            sorted->prev = current;

            if (current->next)
                current->next->prev = sorted;

            current->next = sorted;

            if (current->prev)
                current->prev->next = current;
            else
                *list = current;

            print_list(*list);

            sorted = temp;
        }

        current = current->next;
    }
}
