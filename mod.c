#include "monty.h"
void f_mod(stack_t **head, unsigned int line_number)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*head)->next->n %= (*head)->n;

    f_pop(head, line_number);
}

