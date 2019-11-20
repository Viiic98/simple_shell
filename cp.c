#include "holberton.h"
#define DL " \n\0"
/**
 * cp - function cp
 * @buf: command
 * @arg: rest of the line
 * @env: environment variables
 * Return: Nothing
 **/
void cp(char *buf, char *arg, char **env)
{
	char *argv[] = {"/bin/cp", '\0', NULL};
	int son;

	printf("%s\n", arg);
	/*
	argv[1] = arg;
	
	son = fork();
	if (son == 0)
		execve(argv[0], argv, env);
	wait(&son);
	*/
}
