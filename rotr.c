#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void f_rotr(stack_t **head, unsigned int counter)
{
    stack_t *last = *head;

    (void)counter;

    if (*head == NULL || (*head)->next == NULL)
        return;

    while (last->next != NULL)
        last = last->next;

    last->next = *head;
    (*head)->prev = last;
    *head = last;
    last->prev->next = NULL;
    last->prev = NULL;
}
