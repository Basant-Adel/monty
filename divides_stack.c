#include "monty.h"

/**
 * _div - A function that divides the second element of the stack
 *by the top element of the stack.
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		_div_error(line_number);
	}

	if ((*stack)->next)
	{

		if ((*stack)->n == 0)
		{
			_div_0_error(line_number);
		}

		(*stack)->next->n /= (*stack)->n;
		top_n_del(stack);
	}
	else
	{
		_div_error(line_number);
	}
}

/**
 * _div_error - A function to Print divides ERROR to element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _div_error(int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	all_free();
	exit(EXIT_FAILURE);
}

/**
 * _div_0_error - A function to Print divides (ZERO)->ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _div_0_error(int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	all_free();
	exit(EXIT_FAILURE);
}
