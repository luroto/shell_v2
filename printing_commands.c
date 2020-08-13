#include "shell.h"
/**
 * printing_commands - Function to print the doubly linked list of commands
 * @head: Pointer to the first node
 * Return: It's a void function
 */
void printing_commands(argument_t *head)
{
	while (head != NULL)
	{
		printf("Type: %d, command: %s\n",
			head->tipo, head->com);
		head = head->next;
	}
}
