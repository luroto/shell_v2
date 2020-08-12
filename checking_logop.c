#include "shell.h"
/**
 *
 *
 *
 */
int checking_logop(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '&' && buffer[i + 1] == '&')
			return (2);
		if (buffer[i] == '|')
		{
			if (buffer[i + 1] == '|')
			{
				return (4);
			}
			return (1);
		}
		if (buffer[i] == '>')
		{
			if (buffer[i + 1] == '>')
				return (6);
			return (3);
		}
		if (buffer[i] == '<')
		{
			if (buffer[i + 1] == '<')
				return (8);
			return (5);
		}
		if (buffer[i] == ';')
			return (7);
	}
	return (0);
}
