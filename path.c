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
	struct stat stat_f = {0};

	stat(ic, &stat_f);
	if ((stat_f.st_mode & S_IFMT) == S_IFDIR)
		return (126);
	else if (stat(ic, &stat_f) == 0)
		return (exe_file(ic, arg, env));
	return (exe_command(ic, arg, env));
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
	int son;

	_strcpy(arg[0], ic);
	son = fork();
	if (son == 0)
		execve(arg[0], arg, env);
	wait(&son);
	if (WIFEXITED(son))
		return (WEXITSTATUS(son));
	return (0);
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
	char *str = NULL, *copy = NULL, **dir = NULL;
	struct stat buf;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (_strncmp(env[i], "PATH", 4) == 0)
			break;
	}
	str = alloc_1(str, env[i]);
	dir = alloc_2(dir, str, ":=");
	free(str);

	for (i = 0; dir[i] != NULL; i++)
	{
		copy = alloc_1(copy, dir[i]);
		_strcat(copy, "/");
		_strcat(copy, ic);
		if (stat(copy, &buf) == 0)
		{
			_strcpy(arg[0], copy);
			free(copy);
			_free(dir);
			son = fork();
			if (son == 0)
				execve(arg[0], arg, env);
			wait(&son);
			if (WIFEXITED(son))
				return (WEXITSTATUS(son));
			return (0);
		}
		free(copy);
	}
	_free(dir);
	return (127);
}
/**
 * ferr - check if its a directory
 * @ic: input command
 * Return: -1 if fails, 0 if it doesn't fail
 */
int ferr(char *ic)
{
	int ferr = 0;

	ferr = access(ic, X_OK);

	return (ferr);
}
