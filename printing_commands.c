#include "shell.h"
int printing_commands(argument_t *head)
{
	int size = 0;

	if (head == NULL)
	{
		printf("It's NULL\n");
		return (size);
	}

	while(head != NULL)
	{
		printf("Type: %d, command: %s\n", head->tipo, head->com);
		size++;
		head = head->next;
	}
	return (size);
}
