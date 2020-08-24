#include "shell.h"
/**
*_strstr - Function that founds a substring in a string
*
*@haystack: the string to be checked
*@needle: The string to be serched as substring
*Return: A pointer to the beginning of the found string, otherwise NULL
*/
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0, haystacki = 0, start = 0;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			start = i;
			haystacki = i;
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[haystacki] != needle[j])
				{
					break;
				}
				haystacki++;
			}
		}
	}
	if (needle[j] == '\0')
	{
		return (haystack + start);
	}
	return ('\0');
}
