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
	int arg = 0, cont = 0, i;
	size_t buf_size;
	char *buf;

	buf = malloc(1024 * sizeof(char));
	if (!buf)
	{
		print("Error allocating memory space\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		print("#cisfun$ ");
		arg = getline(&buf, &buf_size, stdin);
		if (arg == -1)
		{
			print("Error\n");
			return (-1);
		}
		if (strcmp(buf, "exit\n") == 0)
			exit(0);
		pipes(buf, env);
	}
	return (0);
}
