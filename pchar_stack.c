#include "monty.h"

/**
 * _pchar - A function to Print the char at the top of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL)
	{
		_pchar_empty_error(line_number);
	}

	number = (*stack)->n;

	if ((number >= 65 && number <= 90) || (number >= 97 && number <= 122))
	{
		printf("%c\n", number);
	}
	else
	{
		_pchar_error(line_number);
	}
}

/**
 * _pchar_error - A function to Print Pchar ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _pchar_error(int line_number)
{

	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	all_free();
	exit(EXIT_FAILURE);

}

/**
 * _pchar_empty_error - A function to Print Pchar Empty ERROR to element
 *message and terminates the program
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _pchar_empty_error(int line_number)
{

	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	all_free();
	exit(EXIT_FAILURE);

}
