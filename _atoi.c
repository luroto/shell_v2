#include "shell.h"
/**
 * very_simple_atoi - Transforms an string into an integer
 * @arg: Argument to be converted
 * Return: The number which was converted
 */
int very_simple_atoi(char *arg)
{
	int i = 0, res = 0;

	for (i = 0; arg[i] != '0'; i++)
		res = res * 10 + arg[i] - '0';
	return (res);

}
