#include "holberton.h"
/**
 * alloc_1 - allocate memory for strings
 * @ptr: pointer that will be allocated
 * @str: value that will be inserted in memory
 * Return: pointer to the new address
 */
void *alloc_1(char *ptr, char *str)
{
	int len;

	len = _strlen(str);
	ptr = malloc(len * sizeof(char *) + 1);
	if (ptr == NULL)
		return (NULL);
	_strcpy(ptr, str);

	return (ptr);
}
/**
 * alloc_2 - allocate memory to double pointers
 * @darg: delimiter to how many args will have
 * @delim: delim for every arg
 * @buf: buffer
 * @ptr: double pointer that will be initialized
 * Return: double pointer allocated
 */
char **alloc_2(char **ptr, char *buf, char *delim, char *darg)
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
		if (buf[i] == darg[0])
			narg++;
		else if (buf[i] == darg[1])
			narg++;
		i++;
	}
	ptr = malloc((narg + 1) * sizeof(char *) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	arg = strtok(buf, delim);
	while (arg)
	{
		len = _strlen(arg);
		ptr[i] = malloc((len + 1) * sizeof(char *) + 1);
		_strcpy(ptr[i], arg);
		arg = strtok(NULL, delim);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
/**
 * _free - free memory to double pointer
 * @ptr: double pointer that will be freed
 * Return: nothing
 */
void _free(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
}
