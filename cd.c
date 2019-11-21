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
		if (strncmp(env[i], "HOME", 4) == 0)
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
			printf("-bash: cd: %s: No such file or directory\n", arg[1]);
	}
}
