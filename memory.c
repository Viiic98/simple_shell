#include "holberton.h"
/**
 * alloc_1 - allocate memory for strings
 * @ptr: pointer that will be allocated
 * @str: value that will be inserted in memory
 * Return: pointer to the new address
 */
void *alloc_1(char *ptr, char *str)
{
	int len, i = 0;

	len = _strlen(str);
	ptr = malloc(len * sizeof(char *) + 1);
	if (ptr == NULL)
		return (NULL);
	_strcpy(ptr, str);

	return (ptr);
}
char **alloc_2(char **ptr, char *buf, char *delim)
{
	char *arg;
	int len, narg = 1, i = 0;

	if (buf == NULL)
	{
		print("Invalid number of arguments");
		return (NULL);
	}
	while (buf[i])
	{
		if (buf[i] == ' ')
			narg++;
		i++;
	}
	ptr = malloc(narg * sizeof(char *) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	arg = strtok(buf, delim);
	while (arg)
	{
		len = _strlen(arg);
		ptr[i] = malloc(len * sizeof(char *) + 1);
		_strcpy(ptr[i], arg);
		arg = strtok(NULL, " \n\0");
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
void _free(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free(ptr[i]);
	free(ptr);
}
