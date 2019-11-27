#include "holberton.h"
/**
 * _cd - function cd
 * @arg: arguments
 * @env: environment variables
 * Return: Nothing
 **/
void _cd(char **arg, char **env)
{
	int status;
	char *str = '\0', *str2 = '\0', *str3 = '\0', *str_old = '\0';

	str_old = _get_cwd();
	if (arg[1] == NULL)
	{
		str = _get_home(env);
		chdir(str);
		setenv("PWD", _get_cwd(), 1);
		setenv("OLDPWD", str_old, 1);
	}
	else if ((_strcmp(arg[1], "-") == 0))
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
 * _get_cwd - function current path
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
	char *str = NULL;
	int i;

	for (i = 0; env[i] != '\0'; i++)
		if (_strncmp(env[i], "HOME", 4) == 0)
			break;
	str = alloc_1(str, env[i]);
	str = strtok(str, "=");
	str = strtok(NULL, "=");
	return (str);
}
/**
 * _get_oldpwd - function path oldpwd
 * @env: environment variables
 * Return: the last path
 **/
char *_get_oldpwd(char **env)
{
	char *str2 = NULL;
	int i;

	for (i = 0; env[i] != '\0'; i++)
		if (_strncmp(env[i], "OLDPWD", 6) == 0)
			break;
	str2 = alloc_1(str2, env[i]);
	str2 = strtok(str2, "=");
	str2 = strtok(NULL, "=");
	return (str2);
}
