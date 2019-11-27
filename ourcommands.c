
#include "holberton.h"
/**
 * pipes - separates line with pipes
 * @buf: line
 * @env: environment variables
 * @n: amount lines
 **/
void pipes(char *buf, char **env, int n)
{
	char **strings = NULL;
	/*parsing line*/
	strings = alloc_2(strings, buf, DELIM);
	ourcommands(strings, env, n);
	_free(strings);
}
/**
 * ourcommands - select the right command
 * @buf: line
 * @env: environment variables
 * @n: amount lines
 **/
void ourcommands(char **buf, char **env, int n)
{
	char **arg = NULL, *ic = NULL, *icopy = NULL;
	int i, perr;

	arg = alloc_2(arg, buf[0], "\"' \n");
	ic = alloc_1(ic, arg[0]);
	icopy = alloc_1(icopy, ic);
	i = 0;
	while (i <= 2)
	{
		if (i == 0 && _strcmp(ic, "cd") == 0)
		{
			_cd(arg, env);
			break;
		}
		else if (i == 1 && _strcmp(ic, "env") == 0)
		{
			_env(env);
			break;
		}
		else if (i == 2)
		{
			perr = (path(ic, arg, env));
			if (perr == 0)
				dprintf(STDERR_FILENO, "bash: %d: %s: not found\n", n, icopy);
			else if (perr == -1)
				dprintf(STDERR_FILENO, "printerror\n");
		}
		i++;
	}
	free(icopy);
	free(ic);
	_free(arg);
}
