#include "shell.h"
/**
 *free_history - Free a linked list used as history
 *@head: Pointer to the first node of the linked list
 *Return: Nothing, void function
 */
void free_history(history_t **head)
{
	history_t *aux;

	while (*head != NULL)
	{
		aux = (*head)->next;
		if ((*head)->com != NULL)
			free((*head)->com);
		free(*head);
		*head = aux;
	}
}
