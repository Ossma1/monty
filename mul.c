#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int line_number)
{
    int result;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*head)->next->n * (*head)->n;
    (*head)->next->n = result;

    f_pop(head, line_number);
}
