#include "monty.h"

/**
 * _pop - A function to Removes the top element of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _pop(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
	{
		stack_empty_error(line_number);
	}

	top_n_del(stack);

}

/**
 * stack_empty_error - A function to Print Empty ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void stack_empty_error(int line_number)
{

	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	all_free();
	exit(EXIT_FAILURE);

}
