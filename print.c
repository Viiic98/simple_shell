#include "holberton.h"

void print(char *str)
{
	int len;

	len = _strlen(str);

	write(STDOUT_FILENO, str, len);
}
int _strlen(char *str)
{
	int len = 0;

	while (*str)
		len++, str++;
	return (len);
}
