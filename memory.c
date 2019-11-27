#include "holberton.h"
/**
 * alloc_1 - allocate memory for strings
 * @ptr: pointer that will be allocated
 * @str: value that will be inserted in memory
 * Return: pointer to the new address
 */
void *alloc_1(char *ptr, char *str)
{
	ptr = malloc(SIZE_BUF * sizeof(char *));
	if (!verify(ptr))
		exit(0);
	_strcpy(ptr, str);
	return (ptr);
}
/**
 * alloc_2 - allocate memory to double pointers
 * @delim: delim for every arg
 * @buf: buffer
 * @ptr: double pointer that will be initialized
 * Return: double pointer allocated
 */
char **alloc_2(char **ptr, char *buf, char *delim)
{
	char *arg = NULL;
	int i = 0;

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Invalid number of arguments\n");
		return (NULL);
	}
	i = 0;
	ptr = malloc(SIZE_BUF * sizeof(char));
	if (!verify(buf))
		return (NULL);
	arg = strtok(buf, delim);
	while (arg)
	{
		ptr[i] = malloc(SIZE_BUF * sizeof(char *));
		if (!verify(buf))
		{
			free(ptr);
			return (NULL);
		}
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
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);
	ptr = NULL;
}
/**
 * verify - function to verify allocated memory
 * @buf: pointer to buffer
 * Return: pointer to buffer
 **/
void *verify(char *buf)
{
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error allocating memory\n");
		return (NULL);
	}
	return (buf);
}
/**
 * veri_buf - verify if buf is null
 * @buf: pointer to buffer
 * Return: 1 if not is null, 0 if is null
 **/
int veri_buf(char *buf)
{
	int narg = 0, i = 0;

	while (buf[i])
	{
		if (buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
		{
			narg++;
			break;
		}
		i++;
	}
	return (narg);
}
