#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *current;

    (void)counter;
    current = *head;
    while (current != NULL && current->n > 0 && current->n <= 127)
    {
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}
