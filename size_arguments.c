#include "shell.h"

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
