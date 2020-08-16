#include "shell.h"
/**
 * command_to_nodes - Tokenizes the buffer in a linked list
 * @head: Pointer to the entire structure
 * @buffer: The entire line from the command line
 * @num: # of executions of this process
 * Return: A pointer to the first node
 */
argument_t *command_to_nodes(argument_t **head, char *buffer, int num)
{
	char *command = NULL;
	int i, j, k, total;

	total = _strlen_recursion(buffer);

	for (i = 0, j = 0; i < total; i++)
	{
		if (is_opera(buffer[i]) == 1)
		{
			k = i - j - (buffer[i - 1] == ' ');
			command = _strndup(buffer + j, k);
			add_command(head, command, num);
			free(command);
			k = is_opera(buffer[i + 1]) + 1;
			command = _strndup(buffer + i, k);
			add_command(head, command, num);
			free(command);
			i += is_opera(buffer[i + 1]) + 1;
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
