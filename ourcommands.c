#include "holberton.h"
/**
 * pipes - separates line with pipes
 * @buf: line
 * @env: environment variables
 **/
void pipes(char *buf, char **env, int n)
{
	char **strings = NULL;

	/*parsing line*/
	strings = alloc_2(strings, buf, DELIM, " ");
	ourcommands(strings, env, n);
}
/**
 * ourcommands - select the right command
 * @buf: line
 * @env: environment variables
 **/
void ourcommands(char **buf, char **env, int n)
{
	char *ic = malloc(sizeof(char *));
	char *icopy = NULL, **arg = NULL;
	int i, perr;

	arg = alloc_2(arg, buf[0], "\"' \n", " \n");
	i = 0;
	ic = arg[0];
	
	icopy = alloc_1(icopy, ic);
	i = 0;
	while (i <= 2)
	{
		if (i == 0 && strcmp(ic, "cd") == 0)
		{
			_cd(arg, env);
			break;
		}
		else if (i == 1 && strcmp(ic, "env") == 0)
		{
			_env(env);
			break;
		}
		else if (i == 2)
		{
			perr = (path(ic, arg, env));
			if (perr == 0)
			{
				printerr("bash: ", n, icopy, ": not found\n");
			}
			else if (perr == -1)
			{
				printerr("bash: ", n, icopy, ": not found\n");
			}
		}
		i++;
	}
	_free(buf);
	_free(arg);
}
