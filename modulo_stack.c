#include "monty.h"

/**
 * _mod - A function to computes the remainder of the division
 *of the second element of the stack by the top element of the stack
 *
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		_mod_error(line_number);
	}

	if ((*stack)->next)
	{

		if ((*stack)->n == 0)
		{
			_div_0_error(line_number);
		}

		(*stack)->next->n %= (*stack)->n;
		top_n_del(stack);
	}
	else
	{
		_mod_error(line_number);
	}
}

/**
 * _mod_error - A function to Print Modulo ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _mod_error(int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	all_free();
	exit(EXIT_FAILURE);
}
