#include "holberton.h"
#define DL " \n\0"
/**
 * ls - function ls
 * @buf: command
 * @arg: rest of the line
 * @env: environment variables
 * Return: Nothing
 **/
void ls(char *buf, char *arg, char **env)
{
	char *argv[] = {"/bin/ls", '\0', NULL};
	int son;

	argv[1] = arg;

	son = fork();
	if (son == 0)
		execve(argv[0], argv, env);
	wait(&son);
}
