#include "shell.h"
/**
 * size_arguments - Calculates the number of arguments introduced
 * from the command line
 * @head: Pointer to the first arg
 * Return: # of arguments
 */

int size_arguments(argument_t *head)
{
	argument_t *aux;
	int i;

	aux = head;
	while (aux != NULL)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
