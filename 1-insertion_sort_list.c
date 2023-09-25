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

    listint_t *sorted, *current;

    sorted = (*list)->next;

    while (sorted)
    {
        current = sorted;
        sorted = sorted->next;

        insert_sorted(list, current);  // Insert the current node into the sorted part
        print_list(*list);            // Print the list after each insertion
    }
}

/**
 * insert_sorted - Inserts a node into the sorted part of a linked list
 *
 * @list: Pointer to the head of the list
 * @node: Node to be inserted
 */
void insert_sorted(listint_t **list, listint_t *node)
{
    listint_t *current;

    if (*list == NULL || node->n <= (*list)->n)
    {
        node->next = *list;
        node->prev = NULL;
        if (*list)
            (*list)->prev = node;
        *list = node;
    }
    else
    {
        current = *list;

        while (current->next && current->next->n < node->n)
            current = current->next;

        node->next = current->next;
        node->prev = current;
        if (current->next)
            current->next->prev = node;
        current->next = node;
    }
}
