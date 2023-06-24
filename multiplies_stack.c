#include "monty.h"

/**
 * _mul - A function to Multiplies the top 2 elements of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		_mul_error(line_number);
	}

	if ((*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		top_n_del(stack);
	}
	else
	{
		_mul_error(line_number);
	}
}

/**
 * _mul_error - A function to Print Multiplies ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _mul_error(int line_number)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	all_free();
	exit(EXIT_FAILURE);
}
