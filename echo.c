#include "holberton.h"
#define DL " \n\0"
/**
 * echo - function echo
 * @buf: command
 * @arg: rest of the line
 * @env: environment variables
 * Return: Nothing
 **/
void echo(char *buf, char *arg, char **env)
{
	char *argv[] = {"/bin/echo", '\0', NULL};
	int son;

	argv[1] = arg;
	
	son = fork();
	if (son == 0)
		execve(argv[0], argv, env);
	wait(&son);
}
