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
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
