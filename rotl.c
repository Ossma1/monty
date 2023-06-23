#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
    stack_t *last = *head;

    (void)counter;

    if (*head == NULL || (*head)->next == NULL)
        return;

    while (last->next != NULL)
        last = last->next;

    last->next = *head;
    (*head)->prev = last;
    *head = (*head)->next;
    (*head)->prev = NULL;
    last->next->next = NULL;
}

