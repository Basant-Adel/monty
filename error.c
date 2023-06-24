#include "monty.h"

/**
 * _usage_error - A function to Print Usage ERROR to element of the stack
 *Return: Void (0) successful
 */

void _usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * _malloc_error - A function to Print Malloc ERROR to element of the stack
 *Return: Void (0) successful
 */

void _malloc_error(void)
{
	all_free();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}

/**
 * inst_invalid_error - A function to Print Invalid Instruction ERROR of stack
 *@line_number: It's a parameter that represents the line number
 *@inst_opcode: It's a parameter that represents the Instruction Opcode
 *Return: Void (0) successful
 */

void inst_invalid_error(int line_number, char *inst_opcode)
{

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, inst_opcode);
	all_free();
	exit(EXIT_FAILURE);
}

/**
 * _fopen_error - A function to Print Open File ERROR to element of the stack
 *@name_f: It's a parameter that represents the Name of File
 *Return: Void (0) successful
 */

void _fopen_error(char *name_f)
{
	fprintf(stderr, "Error: Can't open file %s\n", name_f);
	exit(EXIT_FAILURE);
}
