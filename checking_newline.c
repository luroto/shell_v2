#include "shell.h"
/**
 *checking_newline - Checks the type of operator has been sent
 *@buffer: command to be analyzed
 *Return: >0 if is an operator, otherwise 0
 */
int checking_newline(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (0);
}
