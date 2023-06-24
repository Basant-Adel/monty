#include "monty.h"

data_n data_here = {0, NULL, NULL, NULL, NULL, NULL, STACK};


/**
 * main - It's a Main Monty Function
 *@argc: It's a Number of arguments
 *@argv: It's an Array of argument the string
 *Return: (0)-> Successful (-1)-> Failure
 */

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		_usage_error();
	}

	return (execute_file(argv[1]));

}
