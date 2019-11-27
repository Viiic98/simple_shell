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
	ptr = malloc(len * sizeof(char *));
	if (!verify(ptr))
		exit(EXIT_FAILURE);
	_strcpy(ptr, str);

	return (ptr);
}
/**
 * alloc_2 - allocate memory to double pointers
 * @n_arg: delimiter to how many args will have
 * @delim: delim for every arg
 * @buf: buffer
 * @ptr: double pointer that will be initialized
 * Return: double pointer allocated
 */
char **alloc_2(char **ptr, char *buf, char *delim, int n_arg)
{
	char *arg = NULL;
	int len, i = 0;

	if (buf == NULL)
	{
		print("Invalid number of arguments");
		return (NULL);
	}
	i = 0;
	ptr = malloc((n_arg + 1) * sizeof(char *));
	if (!verify(buf))
		exit(EXIT_FAILURE);
	arg = strtok(buf, delim);
	while (arg)
	{
		len = _strlen(arg);
		ptr[i] = malloc((len + 1) * sizeof(char *));
		if (!verify(buf))
		{
			free(ptr);
			exit(EXIT_FAILURE);
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
		write(STDERR_FILENO, "Error allocating memory\n", 24);
		return (NULL);
	}
	return (buf);
}
/**
 * n_args - function number arguments
 * @buf: pointer to buffer
 * @delim: delimitators
 * Return: Integer number arguments
 **/
int n_args(char *buf, char *delim)
{
	int narg = 1, i = 0, j;

	while (buf[i])
	{
		j = 0;
		while (delim[j])
		{
			if (buf[i] == delim[j])
				narg++;
			j++;
		}
		i++;
	}
	return (narg);
}
