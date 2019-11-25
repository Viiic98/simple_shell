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
void printerr(char *str, char *ic, char *str2)
{
	char *err = NULL;
	int len = 0;

	len += _strlen(str);
	len += _strlen(ic);
	len += _strlen(str2);
	err = malloc((len + 1) * sizeof(char *));
	_strcpy(err, str);
	_strcat(err, ic);
	_strcat(err, str2);
	write(STDERR_FILENO, err, len);
}
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strcpy - Copy the value
 * @dest: Pointer that will recieve the value
 * @src: String that will be copiest
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
