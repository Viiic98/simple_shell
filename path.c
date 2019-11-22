#include "holberton.h"
/**
 * path - function to find the path of the system
 * @ic: function to find
 * @arg: arguments
 * @env: environment variables
 **/
void path(char *ic, char **arg, char **env)
{
	int i, son;
	char *str;
	char *copy = malloc(SIZE_BUF * sizeof(char *));
	char **dir = malloc(SIZE_BUF * sizeof(char *));
	struct stat buf;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (strncmp(env[i], "PATH", 4) == 0)
			break;
	}
	str = alloc_1(str, env[i]);
	str = strtok(str, ":=");
	for (i = 0; str != '\0'; i++)
	{
		str = strtok(NULL, ":=");
		dir[i] = str;
	}
	free(str);
	for (i = 0; dir[i] != '\0'; i++)
	{
		copy = alloc_1(copy, dir[i]);
		strcat(copy, "/");
		strcat(copy, ic);
		if (stat(copy, &buf) == 0)
		{
			arg[0] = copy;
			son = fork();
			if (son == 0)
				execve(arg[0], arg, env);
			wait(&son);
			break;
		}
		free(copy);
	}
}
