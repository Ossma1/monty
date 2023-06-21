#include "monty.h"
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
    char *ligne = NULL;
    size_t taille = 0;
    unsigned int counter = 0;
    ssize_t longueur_ligne;
    stack_t *stack = NULL;
    bus_t bus = {NULL, NULL, NULL, 0};

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    FILE *file = fopen(argv[1], "r");
    bus.file = file;
    if (file == NULL)
    {
        fprintf(stderr,"Error: Can't open file %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((longueur_ligne = getline(&ligne, &taille, file)) > 0)
    {
        counter++;
	bus.content = ligne;
        execute(ligne, &stack, counter, file,&bus);
        free(ligne);
        ligne = NULL;
    }
    stack_t *aux;

	aux = stack;
	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
    fclose(file);
return (0);
}
