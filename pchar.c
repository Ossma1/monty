#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pchar(stack_t **head, unsigned int line_number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
    }

    if ((*head)->n < 0 || (*head)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
    }

    putchar((*head)->n);
    putchar('\n');
}
