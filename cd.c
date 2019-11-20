#include "holberton.h"
/**
 * _cd - function ls
 * Return: Nothing
 **/
void _cd(char **arg, char **env)
{
	int i,j = 5, k = 0, m, n;
	char str[100], *str2, *str3, *str4;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (strncmp(env[i], "HOME", 4) == 0)
			break;
	}
	for (j = 5; env[i][j] != '\0'; j++, k++)
		str[k] = env[i][j];
	if (arg == '\0')
		chdir(str);
	if (arg != '\0')
	{
		str3 = malloc(1024 * sizeof(char));
		for (n = 0; arg[n] != '\0'; n++)
		{
			/*printf("var arg[n] %s", arg[n]);*/
			strcpy(str3, arg[n]);
		}
		printf("str 3 %s", str3);
		/*
		str4 = malloc(1024 * sizeof(char));
		strcpy(str4, str3);
		str2 = malloc(2 * sizeof(char));
		str2 = "/";
		strcat(str3, str2);
		m = chdir(str3);
		if (m == -1)
			printf("-bash: cd: %s: No such file or directory\n", str4);*/
	}
}
