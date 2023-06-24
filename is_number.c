#include "monty.h"

/**
 * is_number - A function to Check if a string is a number or not
 *@str: It's a String
 *Return: (1)-> Valid integer (0)-> Otherwise
 */

int is_number(char *str)
{
	int b = 0;

	if (str[b] == '-')
	{
		b++;
	}

	while (str[b])
	{

		if (!(str[b] >= '0' && str[b] <= '9'))
		{
			return (0);
		}

		b++;
	}

	return (1);
}
