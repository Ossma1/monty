#include "monty.h"

/**
 * f_push - add node to the stack
 * @stack1: stack head
 * @som: line_number
 * Return: no return
 */
void f_push(stack_t **stack1, unsigned int som)
{
	int n, a = 0;
	char *arg;

	arg = strtok(NULL, " \n\t");
	if (arg != NULL)
	{
		if (arg[0] == '-')
			a++;
		for (; arg[a] != '\0'; a++)
		{
			if (arg[a] > 57 || arg[a] < 48)
				break;
		}
		if (arg[a] != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", som);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", som);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack1);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (data_format == S)
		addnode(stack1, n);
	else
		addqueue(stack1, n);
}
