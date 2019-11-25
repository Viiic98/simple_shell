#include "holberton.h"
/**
 * _strcat - Concatenate two strings
 *
 * @dest: Getting the address of a variable to concatenate
 * @src: Word that we go to concatenate
 *
 * Return: The pointer value concatenate
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++, j++;
	}

	dest[i] = '\0';

	return (dest);
}
