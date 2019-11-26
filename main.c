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
	int fd = 0, n = 0;

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
			n++;
			print("#cisfun$ ");
			if (!buf)
			{
				print("Error allocating memory space\n");
				exit(EXIT_FAILURE);
			}
			signal(SIGINT, _catch);
			buf = line(buf);
			if (_strcmp(buf, "exit\n") == 0)
			{
				free(buf);
				exit(0);
			}
/*			if (_strncmp(buf, "exit ", 5) == 0 && buf[5] != '\n')
			{
				if (buf[5] >= 48 && buf[5] <= 57)
				{
					for (i = 5; buf[i] != '\n'; i++)
						;
					status = malloc((i + 1) * sizeof(char));
					if (status != NULL)
					{
						for (i = 5, j = 0; buf[i] != '\n'; i++, j++)
							status[j] = buf[i];
						status[j] =  '\0';
						_atoi(j, status);
						exit(98);
					}
				}
				else
				{	
					exit(0);
				}
			}						
*/			if (buf[0] != '\n')
				pipes(buf, env, n);
		}
	}
	else
	{
		buf = line(buf);
		pipes(buf, env, n);
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
