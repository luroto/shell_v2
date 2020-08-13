#include "shell.h"
/**
 *is_opera - checks if an char is part of or an operator
 * @c: the char to be checked
 * Return: 1 if is part of a operator, otherwise 0
 */
int is_opera(char c)
{
	if (c == '&' || c == '>' || c == '<' || c == '|' || c == ';')
		return (1);
	return (0);
}
