#include "shell.h"
/**
 **_strdup - copies a string on a newly allocated space
 *
 *@str: source string
 *
 *Return: It returns a pointer to the allocated memory
 */
char *_strndup(char *str, int cont)
{
	int contn;
	char *nws;

	if (str == NULL)
	{
		return (NULL);
	}
	nws = malloc(sizeof(*nws) * cont + 1);
	if (nws == NULL)
	{
		free(nws);
		return (NULL);
	}
	for (contn = 0; contn < cont; contn++)
	{
		nws[contn] = str[contn];
	}
	nws[contn] = '\0';
	return (nws);
}
