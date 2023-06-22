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

	if (str[0] == '-')
  {
		is_n++;
  }

	for (; str[is_n] != '\0'; is_n++)
	{
		if (str[is_n] < '0' || str[is_n] > '9')
    {
			return (-1);
    }
	}
  return (0);
}
