#include "shell.h"
/**
 * add_command - add the commands in a doubly linked list
 * @head: The entire structure to be modified
 * @comando: the commando to be added
 * @num: # number of times this process has been executed
 * Return: A pointer to the first node
 */
argument_t *add_command(argument_t **head, char *comando, int num)
{
	argument_t *newnode, *aux;
	int size = 0;

	newnode = malloc(sizeof(argument_t));
	if (newnode == NULL)
	{
		_error(comando, comando, num);
		free_arguments(head);
		exit(EXIT_FAILURE);
	}
	newnode->tipo = checking_logop(comando);
	newnode->next = NULL;
	size = checking_newline(comando);
	if (size != 0)
		newnode->com = _strndup(comando, size);
	else
		newnode->com = _strdup(comando);
	if (newnode->com == NULL)
	{
		_error(comando, comando, num);
		free_arguments(head);
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	aux = *head;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = newnode;
	newnode->prev = aux;
	return (newnode);
}
