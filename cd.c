#include "holberton.h"
/**
 * cd - function ls
 * Return: Nothing
 **/
void _cd(char *arg, char **env)
{
	int i,j = 5, k = 0, m;
	char str[100], *str2, *str3;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (env[i][0] == 'H')
			if (env[i][1] == 'O')
				if (env[i][2] == 'M')
					if (env[i][3] == 'E')
						break;
	}
	for (j = 5; env[i][j] != '\0'; j++, k++)
		str[k] = env[i][j];
	if (arg == '\0')
		chdir(str);
	if (arg != '\0')
	{
		str3 = malloc(1024 * sizeof(char));
		strcpy(str3, arg);
		str2 = malloc(2 * sizeof(char));
		str2 = "/";
		strcat(str3, str2);
		m = chdir(str3);
		if (m == -1)
			printf("-bash: cd: %s: No such file or directory\n", arg);
	}
}
