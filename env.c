#include "holberton.h"
/**
 * _env - Display the environment
 * @env: pointer that contain the environment
 * Return: nothing
 */
void _env(char **env)
{
	int i;

	for (i = 0; env[i] != '\0'; i++)
	{
		print(env[i]);
		print("\n");
	}
}
