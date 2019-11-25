#include "holberton.h"
/**
 * pipes - separates line with pipes
 * @buf: line
 * @env: environment variables
 **/
void pipes(char *buf, char **env)
{
	int i = 0;
	char **strings;
	char *command;

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
	char *ourcommands[3] = {"cd", "env", NULL};
	char **ic = malloc(SIZE_BUF * sizeof(char *));
	char **arg;
	char *a;
	int i = 0, j;

	arg = alloc_2(arg, buf[0], " \n", " \n");
	i = 0;
	ic[0] = arg[0];
	ic[1] = NULL;
	while (ic[i])
	{
		j = 0;

		while (ourcommands[j])
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
			else
			{
				if(path(ic[i], arg, env))
					break;
				else
				{
					print("Command doesn't exist\n");
					break;
				}
			}
			j++;
		}
		i++;
	}
	_free(buf);
	free(ic);
}
