#include "holberton.h"
/**
 * print - Function that print a string to STDOUT
 * @str: string that will be printed
 * Return: Nothing
 */
void print(char *str)
{
	int len;

	len = _strlen(str);

	write(STDOUT_FILENO, str, len);
}
/**
 * _strlen - Fucntion that count characters of a string
 * @str: string
 * Return: Number of characters
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strcpy - Copy the value
 *
 * @dest: Pointer that will recieve the value
 * @src: String that will be copiest
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
