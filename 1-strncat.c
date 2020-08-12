#include "shell.h"
/**
 *_strncat - concatenates two strings until n bytes
 *
 *@dest: string which receives
 *
 *@src: source string which will be used as appendixx
 *
 *@n: provided number of bytes
 *
 *Return: It's supposed to be the dest pointer
 */
char *_strncat(char *dest, char *src, int n)
{
	int idest = 0, isrc = 0, i = 0;

	while (dest[idest])
		idest++;
	while (src[isrc])
		isrc++;
	if (isrc < n)
	{
		n = isrc;
	}
	while (i < n)
	{
		dest[idest + i] = src[i];
		i++;
	}
	return (dest);
}
