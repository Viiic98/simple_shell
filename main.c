#include "holberton.h"
/**
 * main - principal program shell
 * @ac: amount arguments
 * @av: arguments
 * @env: environment variables
 * Return: 0 if succeed
 **/
int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	int fd = 0, n = 0;

	if (ac > 1)
	{
		print(av[0]);
		exit(0);
	}
	fd = isatty(fd);
	if (fd == 1)
	{
		while (1)
		{
			n++;
			print("#cisfun$ ");
/*			signal(SIGINT, _catch);
 */			buf = line(buf);
			if (_strcmp(buf, "exit\n") == 0)
			{
				free(buf);
				exit(0);
			}
/*			if (_strncmp(buf, "exit ", 5) == 0 && buf[5] != '\n')
			{
				_exit_arg(buf);
			}
*/			if (buf[0] != '\n')
				pipes(buf, env, n);
			free(buf);
		}
	}
	else
	{
		buf = line(buf);
		pipes(buf, env, n);
		free(buf);
		exit(0);
	}
	return (0);
}
/**
 * line - get an input line
 * @buf: pointer to buffer
 * Return: pointer to the buffer
 */
void *line(char *buf)
{
	int arg = 0;
	size_t buf_size = 0;

	arg = getline(&buf, &buf_size, stdin);
	if (arg == -1)
	{
		print("Error getting the value\n");
		return (NULL);
	}
	return (buf);
}
/**
 * _catch - function to catch ctrl c
 * @signal: value of the signal catched
 * Return: value of signal
 **/
void _catch(int signal)
{
	signal = signal * 1;
	print("\n");
	print("#cisfun$ ");
}
/**
 * _exit_arg - function exit with status argument
 * @buf: pointer to buffer
 **/
void _exit_arg(char *buf)
{
	int i, j;
	char *status;

	if (buf[5] >= 48 && buf[5] <= 57)
	{
		for (i = 5; buf[i] != '\n'; i++);
		status = malloc(sizeof(char *));
		if (status != NULL)
		{
			for (i = 5, j = 0; buf[i] != '\n'; i++, j++)
				status[j] = buf[i];
			status[j] =  '\0';
			i = 0;
			i = _atoi(j, status);
			free(status);
			exit(i);
		}
	}
	else
	{
		exit(0);
	}
}
