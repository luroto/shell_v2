#include "shell.h"
/**
*get_argument - Function that founds a substring in a string
*
*@hay: the string to be checked
*@needle: The string to be serched as substring
*Return: A pointer to the beginning of the found string, otherwise NULL
*/
int *get_argument(char *hay, char *needle)
{
	int i = 0, j = 0, haystacki = 0, start = 0;
	static int position[2];

	for (i = 0; hay[i] != '\0'; i++)
	{
		if (hay[i] == needle[0])
		{
			start = i;
			haystacki = i;
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (hay[haystacki] != needle[j])
				{
					break;
				}
				haystacki++;
			}
		}
	}
	if (needle[j] == '\0')
	{
		while (hay[haystacki] == ' ')
			haystacki++;
		start = haystacki;
		while (hay[haystacki] != '\n' && hay[haystacki] != ' ')
			haystacki++;
		position[0] = start;
		position[1] = haystacki - start;
	}
	return (position);
}
