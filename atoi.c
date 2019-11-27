#include "holberton.h"
/**
 * _atoi - function to convert char to int
 * @i: length of second argument
 * @buf: chars second argument
 **/
int _atoi(int i, char* buf)
{
	char letters[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };   
	int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int j, k, res = 0, num, flag, n = 1, p, exp, div = 0;

	for (j = 0; buf[j] != '\0'; j++)
	{
		flag = 0;
		exp = 1;
		for (k = 0; k < 10; k++)
		{
			if (buf[j] == letters[k])
			{
				num = numbers[k];
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{			
			for (p = i - n; p > 0; p--)
				exp *= 10;
			if (i - n > 0)
				res += num * exp;
			if (i - n == 0)
				res += num;
			n++;
		}
		if (flag == 0)
			exit(0);
	}
	if (res >= 256 && res < 2147483647)
	{
		div = res / 256;
		return (res - (256 * div));
	}
	if (res < 256)
		return (res);
	return (0);
}
