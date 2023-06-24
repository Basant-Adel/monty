#include "monty.h"

/**
 * _swap - A function in the Monty language interpreter that swaps
 *the positions of the top two elements of the stack.
 *
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _swap(stack_t **stack, unsigned int line_number)
{

	int element;

	if (stack == NULL || *stack == NULL)
	{
		_swap_error(line_number);
	}

	if ((*stack)->next)
	{
		element = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = element;
	}
	else
	{
		_swap_error(line_number);
	}

}

/**
 * _swap_error - A function to Print Swap ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _swap_error(int line_number)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	all_free();
	exit(EXIT_FAILURE);

}
