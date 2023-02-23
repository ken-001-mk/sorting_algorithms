#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *p, *q;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped) {
        swapped = 0;
        for (p = *list; p->next != NULL; p = p->next) {
            if (p->n > p->next->n) {
                q = p->next;
                if (p->prev != NULL)
                    p->prev->next = q;
                else
                    *list = q;
                q->prev = p->prev;
                p->prev = q;
                p->next = q->next;
                if (q->next != NULL)
                    q->next->prev = p;
                q->next = p;
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (q = p->prev; q != NULL; q = q->prev) {
            if (q->n > q->next->n) {
                p = q->next;
                if (q->prev != NULL)
                    q->prev->next = p;
                else
                    *list = p;
                p->prev = q->prev;
                q->prev = p;
                q->next = p->next;
                if (p->next != NULL)
                    p->next->prev = q;
                p->next = q;
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

