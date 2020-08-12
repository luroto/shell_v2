#include "shell.h"
argument_t *command_to_nodes(argument_t **head, char *buffer, int oper, int num)
{
	char *command = NULL;
	int i, j, k, total;
	
	total = _strlen_recursion(buffer);

	for (i = 0, j = 0; i < total; i++)
	{
		if (is_opera(buffer[i]) == 1)
		{
			if (buffer[i - 1] == ' ')
				k = i - 1;
			else
				k = i;
			command = _strndup(buffer + j , k);
			add_command(head, command, num);
			free(command);
			if (oper % 2 == 0)
				k = 2;
			else
				k = 1;
			command = _strndup(buffer + i, k);
			add_command(head, command, num);
			free(command);
			if (oper % 2 == 0)
				i += 2;
			else 
				i++;
			while (buffer[i] == ' ')
				i++;
			j = i;
		}
	}
	k = total - j;
	command = _strndup(buffer + j, k);
	add_command(head, command, num);
	free(command);
	return (*head);
}
