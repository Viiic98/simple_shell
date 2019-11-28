#include "holberton.h"
/**
 * _env - Display the environment
 * @env: pointer that contain the environment
 * Return: nothing
 */
int _env(char **env)
{
	int i;

	for (i = 0; env[i] != '\0'; i++)
		dprintf(STDOUT_FILENO, "%s\n", env[i]);
	return (0);
}
