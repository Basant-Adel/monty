#include "monty.h"

/**
 * _add - A function to Adds the top 2 elements of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		_add_error(line_number);
	}

	if ((*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		top_n_del(stack);
	}
	else
	{
		_add_error(line_number);
	}
}

/**
 * _add_error - A function to Print Adds ERROR to elements of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _add_error(int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	all_free();
	exit(EXIT_FAILURE);
}
