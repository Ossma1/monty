#include "monty.h"
    /**
     * execute - executes the opcode
     * @stack: head linked list - stack
     * @counter: line_counter
     * @file: poiner to monty file
     * @content: line content
     * Return: no return
     */
    
int execute(char *ligne, stack_t **stack, unsigned int counter, FILE *file)
{
    unsigned int j = 0;
    instruction_t opst[] = {
        {"push", f_push},
        {"pall", f_pall},
        {NULL, NULL}};
    char *operation = strtok(ligne, " \n\t");
    ;
    
    if (operation[0] == "#")
    {
	    return (0);
    }
    while (opst[j].opcode && operation)
    {
        if (strcmp(operation, opst[j].opcode) == 0)
        {
            opst[j].f(stack, counter);
            return (0);
        }
        j++;
    }
    if (operation && opst[j].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
        fclose(file);
        free(ligne);
	free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    return (1);
}
