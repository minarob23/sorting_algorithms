#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev1 = node1->prev;
    listint_t *next2 = node2->next;

    if (prev1)
        prev1->next = node2;
    else
        *list = node2;

    if (next2)
        next2->prev = node1;

    node1->prev = node2;
    node1->next = next2;
    node2->prev = prev1;
    node2->next = node1;

    print_list(*list);  // Print the list after each swap
}

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

    listint_t *current, *temp;

    current = (*list)->next;
    while (current)
    {
        temp = current;

        while (temp->prev && temp->n < temp->prev->n)
        {
            swap_nodes(list, temp->prev, temp);
            temp = temp->prev;
        }

        current = current->next;
    }
}
