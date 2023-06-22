#include "monty.h"

/**
 * multiplies_stack - A function to Multiplies the top 2 elements of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void multiplies_stack(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL || (*stack)->next == NULL)
	/* It checks if the stack is either empty or has only one element. */
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->next->n;
	number = number * (*stack)->n;
	pop_stack(stack, line_number);
	(*stack)->n = number;
}
