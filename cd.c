#include "holberton.h"
/**
 * _cd - function cd
 * @arg: arguments
 * @env: environment variables
 * Return: Nothing
 **/
void _cd(char **arg, char **env)
{
	int i, status;
	char *str, *str2, *str3, *str_old, *str_home;

	str_old = _get_cwd();
	str_home = _get_home(env);
	if (arg[1] == NULL)
	{
		chdir(str);
		setenv("PWD", _get_cwd(), 1);
		setenv("OLDPWD", str_old, 1);
	}
	if (_strcmp(arg[1], "-") == 0)
	{
		str2 = _get_oldpwd(env);
		chdir(str2);
		str3 = _get_cwd();
		setenv("PWD", str3, 1);
		setenv("OLDPWD", str_old, 1);
	}
	else
	{
		status = chdir(arg[1]);
		if (status == -1)
		{
			print("-bash: cd: ");
			print(arg[1]);
			print(": No such file or directory\n");
		}
		if (status != -1)
		{
			setenv("PWD", _get_cwd(), 1);
			setenv("OLDPWD", str_old, 1);
		}
	}
}
/**
 * _get_oldp - function old path
 * Return: the current path
 **/
char *_get_cwd(void)
{
	char *str3;

	str3 = malloc(SIZE_BUF * sizeof(char));
	if (str3 != NULL)
		str3 = getcwd(str3, SIZE_BUF);
	return (str3);
}
/**
 * _get_home -function path home
 * @env: environment variables
 * Return: the home path
 **/
char *_get_home(char **env)
{
	char *str;
	int i;

	for (i = 0; env[i] != '\0'; i++)
		if (_strncmp(env[i], "HOME", 4) == 0)
			break;
	str = strtok(env[i], "=");
	str = strtok(NULL, "=");
	return (str);
}
/**
 * _get_oldpwd - function path oldpwd
 * @env: environment variables
 * Return : the last path
 **/
char *_get_oldpwd(char **env)
{
	char *str2;
	int i;

	for (i = 0; env[i] != '\0'; i++)
		if (strncmp(env[i], "OLDPWD", 6) == 0)
			break;
	str2 = alloc_1(str2, env[i]);
	str2 = strtok(str2, "=");
	str2 = strtok(NULL, "=");
	return (str2);
}

