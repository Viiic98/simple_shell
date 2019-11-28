#include "holberton.h"
/**
 * _env - Display the environment
 * @env: pointer that contain the environment
 * Return: nothing
 */
int _env(char **env)
{
	int i, len = 0;

	for (i = 0; env[i] != '\0'; i++)
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
