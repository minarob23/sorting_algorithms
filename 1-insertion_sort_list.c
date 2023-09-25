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

    listint_t *current, *prev, *temp;

    current = (*list)->next;

    while (current)
    {
        prev = current->prev;

        while (prev && prev->n > current->n)
        {
            temp = prev->prev;

            if (prev->next)
                prev->next->prev = prev;

            prev->next = current->next;
            current->prev = prev->prev;
            current->next = prev;
            prev->prev = current;

            if (current->prev)
                current->prev->next = current;
            else
                *list = current;

            print_list(*list);  // Print the list after each swap

            prev = temp;
        }

        current = current->next;
    }
}

/**
 * swap_node - Swaps a node with its previous one in a linked list
 *
 * @node: Node to be swapped
 * @list: Pointer to the head of the list
 * Return: Pointer to the node that was swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *back = node->prev;
    listint_t *current = node;

    back->next = current->next;
    if (current->next)
        current->next->prev = back;
    current->next = back;
    current->prev = back->prev;
    back->prev = current;

    if (current->prev)
        current->prev->next = current;
    else
        *list = current;

    return (current);
}
