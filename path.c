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
	int nint_mode = 0;
	struct stat buf;

	if (stat(ic, &buf) == 0)
		nint_mode = exe_file(ic, arg, env);
	else
		nint_mode = ferr(ic);
	if (nint_mode == 0)
	{
		return (exe_command(ic, arg, env));
	}
	return (nint_mode);
}
/**
 * exe_file - Execute a file that exists in path
 * @ic: input command
 * @arg: arguments
 * @env: environment
 * Return: 1 if success
 */
int exe_file(char *ic, char **arg, char **env)
{
	int son, ferr = 0;
	char *copy;

	arg[0] = ic;
	son = fork();
	if (son == 0)
		execve(arg[0], arg, env);
	wait(&son);
	_free(arg);
	return (1);
}
/**
 * exe_command - execute a command
 * @ic: input command
 * @arg: arguments
 * @env: environment
 * Return: 1 if success, 0 if it fails
 */
int exe_command(char *ic, char **arg, char **env)
{
	int i;
	pid_t son;
	char *str = NULL, *copy, **dir = NULL;
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
/**
 * ferr - check if its a directory
 * @ic: input command
 * Return: -1 if fails, 0 if it doesn't fail
 */
int ferr(char *ic)
{
	int ferr = 0;
	char *copy;

	copy = alloc_1(copy, ic);
	copy = strtok(copy, "/");
	while (copy)
	{
		copy = strtok(NULL, "/");
		ferr++;
	}
	if (ferr >= 2)
		return (-1);
	return (0);
}
