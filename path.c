#include "holberton.h"
/**
 * path - function to find the path of the system
 * @ic: function to find
 * @arg: arguments
 * @env: environment variables
 **/
int path(char *ic, char **arg, char **env)
{
	int i;
	pid_t son;
	char *str;
	char *copy;
	char **dir;
	struct stat buf;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (_strncmp(env[i], "PATH", 4) == 0)
			break;
	}
	str = alloc_1(str, env[i]);
	dir = alloc_2(dir, str, ":=", ":=");
	free(str);
	for (i = 0; dir[i] != NULL; i++)
	{
		copy = alloc_1(copy, dir[i]);
		_strcat(copy, "/");
		_strcat(copy, ic);
		if (stat(copy, &buf) == 0)
		{
			arg[0] = copy;
			son = fork();
			if (son == 0)
				execve(arg[0], arg, env);
			wait(&son);
			_free(arg);
			_free(dir);
			return (1);
		}
		free(copy);
	}
	_free(arg);
	_free(dir);
	return (0);
}
