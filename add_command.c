#include "shell.h"

argument_t *add_command(argument_t **head, char *comando, int num)
{
	argument_t *newnode, *aux;

	newnode = malloc(sizeof(argument_t));
	if (newnode == NULL)
	{
		_error(comando, comando, num);
		free_arguments(head);
		exit (EXIT_FAILURE);
	}
	newnode->tipo = 0;
	newnode->next = NULL;
	newnode->com = _strdup(comando);
	if  (newnode->com == NULL)
	{
		_error(comando, comando, num);
		free_arguments(head);
		exit (EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	aux = *head;
	while(aux->next != NULL)
		aux = aux->next;
	aux->next = newnode;
	newnode->prev = aux;
	return (newnode);
}
