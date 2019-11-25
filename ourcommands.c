#include "holberton.h"
/**
 * pipes - separates line with pipes
 * @buf: line
 * @env: environment variables
 **/
void pipes(char *buf, char **env)
{
	char **strings = NULL;

	/*parsing line*/
	strings = alloc_2(strings, buf, DELIM, " ");
	ourcommands(strings, env);
}
/**
 * ourcommands - select the right command
 * @buf: line
 * @env: environment variables
 **/
void ourcommands(char **buf, char **env)
{
	char **ic = malloc(SIZE_BUF * sizeof(char *));
	char *icopy, **arg = NULL;
	int i = 0, j, perr;

	arg = alloc_2(arg, buf[0], "\"' \n", " \n");
	i = 0;
	ic[0] = arg[0];
	ic[1] = NULL;
	while (ic[i])
	{
		icopy = alloc_1(icopy, ic[i]);
		j = 0;
		while (j <= 2)
		{
			if (j == 0 && strcmp(ic[i], "cd") == 0)
			{
				_cd(arg, env);
				break;
			}
			else if (j == 1 && strcmp(ic[i], "env") == 0)
			{
				_env(env);
				break;
			}
			else if (j == 2)
			{
				perr = (path(ic[i], arg, env));
				if (!perr)
				{
					print(icopy);
					print(": command not found\n");
				}
			}
			j++;
		}
		i++;
		free(icopy);
	}
	_free(buf);
	free(ic);
}
