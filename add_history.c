#include "shell.h"
/**
 * add_history - add the commands in a doubly linked list
 * @head: The entire structure to be modified
 * @comando: the commando to be added
 * @num: # number of times this process has been executed
 * Return: A pointer to the first node
 */
history_t *add_history(history_t **head, char *comando, int num)
{
	history_t *newnode, *aux;

	newnode = malloc(sizeof(history_t));
	if (newnode == NULL)
	{
		_error(comando, comando, num);
		exit(EXIT_FAILURE);
	}
	newnode->num = num - 1;
	newnode->next = NULL;
	newnode->com = _strdup(comando);
	if  (newnode->com == NULL)
	{
		_error(comando, comando, num);
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	aux = *head;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = newnode;
	return (newnode);
}
