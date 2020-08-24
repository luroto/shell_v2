#include "shell.h"
/**
 * _strlen - count length  of a string
 * @s: string to count
 * Return: number of characters
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (s[i])
		i++;

	return (i);
}
#include "shell.h"
/**
 * cd_fun - entry current path
 * @args: the path or options
 */
void cd_fun(char *args)
{
	int file, index;

	if (args == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(args, "-") == 0)
	{
		puts(args);
	}

	else
	{
		file = chdir(args);
		if (file < 0)
			perror(args);
	}
}
/**
 * find_path - Finds the index of an environmental variable.
 * @str: Environmental variable that needs to be found.
 * Return: Upon success returns the index of the environmental variable.
 * otherwise returns -1.
 */
int find_path(char *str)
{
	int i;
	int len;
	int j;

	len = _strlen(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}
