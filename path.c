#include "holberton.h"

void path(char *ic, char **arg, char **env)
{
	int i, son;
	char *str = malloc(SIZE_BUF * sizeof(char *));
	char **pcopy = malloc(SIZE_BUF * sizeof(char *));
	char *copy = malloc(SIZE_BUF * sizeof(char *));
	char **dir = malloc(SIZE_BUF * sizeof(char *));
	struct stat buf;
	
	for(i = 0; env[i] != '\0'; i++)
	{
		if (strncmp(env[i], "PATH", 4) == 0)
			break;
	}
	strcpy(str, env[i]);
	str = strtok(str, ":=");
	for (i = 0; str != '\0'; i++)
	{
		str = strtok(NULL, ":=");
		dir[i] = str;
	}
	for(i = 0; dir[i] != '\0'; i++)
	{
		strcpy(copy, dir[i]);
		strcat(copy, "/");
		strcat(copy, ic);
		if(stat(copy, &buf) == 0)
		{
			arg[0] = copy;
			son = fork();
			if (son == 0)
				execve(arg[0], arg, env);
			wait(&son);
			break;
		}
	}
}
