#include "monty.h"

/**
 * is_number - A function to Check if a string is a number or not
 *@str: It's a String
 *Return: Depend Condition
*/

int is_number(char *str)
{
	int is_n = 0;

	str = strtok(str, " \n");

	if (!str)
	{
		return (0);
	}

	if (str[0] == '-')
	{
		is_n++;
	}

	while (str[is_n])
	{
		if (str[is_n] < '0' || str[is_n] > '9')
		{
			return (0);
		}
		is_n++;
	}
	return (1);
}
