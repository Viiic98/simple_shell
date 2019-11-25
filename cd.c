#include "holberton.h"
/**
 * _cd - function cd
 * @arg: arguments
 * @env: environment variables
 * Return: Nothing
 **/
void _cd(char **arg, char **env)
{
	int i, status;
	char *str;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (_strncmp(env[i], "HOME", 4) == 0)
			break;
	}
	str = strtok(env[i], "=");
	str = strtok(NULL, "=");

	if (arg[1] == NULL)
	{
		chdir(str);
	}
	else
	{
		status = chdir(arg[1]);
		if (status == -1)
		{
			print("-bash: cd: ");
			print(arg[1]);
			print(": No such file or directory\n");
		}
	}
}
