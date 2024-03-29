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
	int fd = 0, n = 0, status = 0;

	if (ac > 1)
	{
		dprintf(STDERR_FILENO, "bash: 0: Can't open %s\n", av[1]);
		exit(127);
	}
	fd = isatty(fd);
	while (1)
	{
		n++;
		if (fd == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		buf = line(buf);
		if (buf == NULL)
			exit(status);
		if (veri_buf(buf) == 1)
		{
			if (_strcmp(buf, "exit\n") == 0)
			{
				free(buf);
				exit(status);
			}
			if (buf[0] != '\n')
				status = pipes(buf, env, n);
		}
		free(buf);
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
		free(buf);
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
	dprintf(STDOUT_FILENO, "\n#cisfun$ ");
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
		for (i = 5; buf[i] != '\n'; i++)
			;
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
