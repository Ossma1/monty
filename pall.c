#include "monty.h"

/**
 * f_pall - prints the stack
 * @stack1: stack head
 * @counter: not used
 * Return: no return
 */
void f_pall(stack_t **stack1, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *stack1;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
