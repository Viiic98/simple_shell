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
	char *buf;
	int fd = 0;

	if (ac > 1)
	{
		print(av[0]);
		exit(EXIT_FAILURE);
	}
	buf = malloc(1024 * sizeof(char *));
	fd = isatty(fd);
	if (fd == 1)
	{
		while (1)
		{
			print("#cisfun$ ");
			if (!buf)
			{
				print("Error allocating memory space\n");
				exit(EXIT_FAILURE);
			}
			buf = line(buf);
			if (_strcmp(buf, "exit\n") == 0)
			{
				free(buf);
				exit(0);
			}
			if (buf[0] != '\n')
				pipes(buf, env);
		}
	}
	else
	{
		buf = line(buf);
		pipes(buf, env);
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
	size_t buf_size;

	arg = getline(&buf, &buf_size, stdin);
	if (arg == -1)
	{
		print("Error getting the value\n");
		return (NULL);
	}
	return (buf);
}
