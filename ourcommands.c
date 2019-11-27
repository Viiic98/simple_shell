
#include "holberton.h"
/**
 * pipes - separates line with pipes
 * @buf: line
 * @env: environment variables
 * @n: amount of lines executed
 * Return: command status
 **/
int pipes(char *buf, char **env, int n)
{
	char **strings = NULL;
	int status = 0;
	/*parsing line*/
	strings = alloc_2(strings, buf, DELIM);
	status = ourcommands(strings, env, n);
	_free(strings);
	return (status);
}
/**
 * ourcommands - select the right command
 * @buf: line
 * @env: environment variables
 * @n: amount lines
 * Return: command status
 **/
int ourcommands(char **buf, char **env, int n)
{
	char **arg = NULL, *ic = NULL, *icopy = NULL;
	int i, status = 0;

	arg = alloc_2(arg, buf[0], "\"'\t \n");
	ic = alloc_1(ic, arg[0]);
	icopy = alloc_1(icopy, ic);
	i = 0;
	while (i <= 2)
	{
		if (i == 0 && _strcmp(ic, "cd") == 0)
		{
			status = _cd(arg, env, n);
			break;
		}
		else if (i == 1 && _strcmp(ic, "env") == 0)
		{
			_env(env);
			break;
		}
		else if (i == 2)
		{
			status = (path(ic, arg, env));
			if (status == 127)
				dprintf(STDERR_FILENO, "bash: %d: %s: not found\n", n, icopy);
			else if (status == 126)
				dprintf(STDERR_FILENO, "sh: %d: %s: Permission denied\n", n, icopy);
		}
		i++;
	}
	free(icopy);
	free(ic);
	_free(arg);
	return (status);
}
