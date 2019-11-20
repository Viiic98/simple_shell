#include "holberton.h"
/**
 * pipes - separates line with pipes
 * @buf: line
 * @env: environment variables
 **/
void pipes(char *buf, char **env)
{
	int i = 0;
	char **strings = malloc(1024 * sizeof(char *));
	char *command;

	/*parsing line*/
	command = strtok(buf, DELIM);
	while (command != NULL)
	{
		strings[i] = command;
		i++;
		command = strtok(NULL, DELIM);
	}
	ourcommands(strings, env);
}
/**
 * ourcommands - select the right command
 * @buf: line
 * @env: environment variables
 **/
void ourcommands(char **buf, char **env)
{
	char *ourcommands[8] = {"ls", "cd", "cp", "pwd", "echo", "env", "rm", "\0"};
	char **ic = malloc(1024 * sizeof(char *)); 
	char **arg = malloc(1024 * sizeof(char *));
	char *a;
	int i = 0, j;

	a =  strtok(buf[i], " \n\0");
	ic[i] = a;
	while (a)
	{
		arg[i] = a;
		a = strtok(NULL, " \n\0");
		i++;
	}
	i = 0;
	while (ic[i])
	{
		j = 0;

		while (ourcommands[j])
		{
			if (j == 1 && strcmp(ic[i], "cd") == 0)
				_cd();
			else if (j == 5 && strcmp(ic[i], "env") == 0)
				_env(env);
			else if (strcmp(ourcommands[j], ic[i]) == 0)
			{	
				path(ic[i], arg, env);
				break;
			}
		       	j++;
		}
		i++;
	}
}
