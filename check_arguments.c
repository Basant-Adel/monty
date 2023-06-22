#include "monty.h"

/**
 * check_arguments - A function to Check if the arguments are correct or not
 *@argc: It's an Argument Number
 *@argv: It's an Argument Vector
 *@file: It's a File
 *Return: Depend Condition
 *
*/

void check_arguments(int argc, char *argv[], FILE *file)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	/*To check if the value of the pointer variable file is pointing to NULL*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
