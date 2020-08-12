#include "shell.h"
/**
 *_strncpy - copy two strings until n bytes
 *
 *@dest: string which receives
 *
 *@src: source string which will replace on dest string until n bytes
 *
 *@n: provided number of bytes
 *
 *Return: It's supposed to be the dest pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, isrc = 0;

	while (src[isrc])
	{
		isrc++;
	}
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
