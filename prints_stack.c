#include "monty.h"

/**
 * _pint - A function that prints the value at the top of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		_pint_error(line_number);
	}

	printf("%d\n", (*stack)->n);

}

/**
 * _pint_error - A function to Print Pint ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _pint_error(int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	all_free();
	exit(EXIT_FAILURE);
}
