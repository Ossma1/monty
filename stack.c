#include "monty.h"

void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;

    data_format = S;
}

void addnode(stack_t **head, int n)

{
    stack_t *new_node, *temp;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        temp = *head;
        new_node->next = temp;
        temp->prev = new_node;
        *head = new_node;
    }
}
