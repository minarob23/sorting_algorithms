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

    listint_t *current;
    listint_t *prev;

    current = (*list)->next;
    while (current)
    {
        prev = current->prev;

        while (prev && prev->n > current->n)
        {
            if (current->next)
                current->next->prev = prev;

            prev->next = current->next;
            current->prev = prev->prev;
            current->next = prev;
            prev->prev = current;

            if (current->prev)
                current->prev->next = current;
            else
                *list = current;

            print_list(*list);

            prev = current->prev;
        }
        current = current->next;
    }
}
