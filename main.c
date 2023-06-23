#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"

bus_t bus = {NULL, NULL};
DataFormat data_format = S; 
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
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
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
        execute(ligne, &stack, counter, file);
        free(ligne);
        ligne = NULL;
    }
    free_stack(stack);
    fclose(file);
return (0);
}

