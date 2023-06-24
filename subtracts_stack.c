#include "monty.h"

/**
 * _sub - A function that subtracts the top and second top elements of stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _sub(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
	{
		_sub_error(line_number);
	}

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		top_n_del(stack);
	}
	else
	{
		_sub_error(line_number);
	}

}

/**
 * _sub_error - A function to Print Sub ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _sub_error(int line_number)
{

	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	all_free();
	exit(EXIT_FAILURE);

}
