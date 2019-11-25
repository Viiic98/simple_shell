#include "holberton.h"
/**
 * path - function to find the path of the system
 * @ic: function to find
 * @arg: arguments
 * @env: environment variables
 * Return: 1 if success, 0 if it fails
 **/
int path(char *ic, char **arg, char **env)
{
	int i, int_mode = 0;
	pid_t son;
	char *str = NULL;
	char *copy;
	char **dir = NULL;
	struct stat buf;


	if (stat(ic, &buf) == 0)
		int_mode = non_interactive(ic, arg, env);
	if (int_mode == 0)
	{
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
	return (1);
}
int non_interactive(char *ic, char **arg, char **env)
{
	int son;
	
	arg[0] = ic;
	son = fork();
	if (son == 0)
		execve(arg[0], arg, env);
	wait(&son);
	_free(arg);
	return (1);
}
