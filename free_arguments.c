#include "shell.h"
/**
 *free_arguments - Free a doubly linked list of entries from readdir
 *@head: Pointer to the first node of the linked list
 *Return: Nothing, void function
 */
void free_arguments(argument_t **head)
{
	argument_t *aux;

	while (*head != NULL)
	{
		aux = (*head)->next;
		free((*head)->com);
		free(*head);
		*head = aux;
	}
}
