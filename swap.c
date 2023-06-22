#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int line_number)
{
    int temp;
    
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}

