#include "holberton.h"
/**
 * _strcmp - Function that compares two strings
 * @s1: First string that will be compared
 * @s2: Second string that will be compared
 * Return: Integer depends that the ASCII table
 */
int _strcmp(char *s1, char *s2)
{
	int i, a = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		a = a + (s1[i] - s2[i]);
		if (a != 0)
			break;
	}
	return (a);
}
/**
 * _strncmp - Function that compares c chars between two strings
 * @s1: First string that will be compared
 * @s2: Second string that will be compared
 * @c: Amount of characters
 * Return: Integer depends that the ASCII table
 */
int _strncmp(char *s1, char *s2, int c)
{
	int i, a = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < c; i++)
	{
		a = a + (s1[i] - s2[i]);
		if (a != 0)
			break;
	}
	return (a);
}
