#include "shell.h"
/**
 * checking_builtins - checking for some builtins
 * @buffer: Buffer from getline
 * @head: Pointer to history nodes
 * Return: 1 if one of them is executed, otherwise 0
 */
int checking_builtins(char *buffer, history_t **head)
{
	char *me = "exit\n", *arg = NULL, *check = NULL;
	int code = 0;
	int *position = NULL;

	if (_strcmp(buffer, me) == 0)
	{
		free(buffer);
		free_history(head);
		exit(0);
	}
	else if (_strcmp(buffer, "history\n") == 0)
	{
		printing_history(*head);
		return (1);
	}
	else if (_strcmp(buffer, "cd\n") == 0)
	{
		cd_fun(arg);
		return (1);
	}
	else if (_strstr(buffer, "cd") != NULL)
	{
		position = get_argument(buffer, "cd");
		arg = _strndup(buffer + position[0], position[1]);
		cd_fun(arg);
		free(arg);
		return (1);
	}
	else if (_strstr(buffer, "exit") != NULL)
	{
		position = get_argument(buffer, "exit");
		arg = _strndup(buffer + position[0], position[1]);
		code = very_simple_atoi(arg);
		free(arg);
		free(buffer);
		free_history(head);
		exit(code);
	}
	return (0);
}
