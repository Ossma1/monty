#include "monty.h"
/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int line_number)
{
    int result;
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    result = (*head)->next->n / (*head)->n;
    (*head)->next->n = result;

    f_pop(head, line_number);
}
