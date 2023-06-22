#include "monty.h"

/**
 * add_stack - A function to Adds the top 2 elements of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void add_stack(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL || (*stack)->next == NULL)
	/* It checks if the stack is either empty or has only one element. */
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->next->n;
	number = number + (*stack)->n;
	pop_stack(stack, line_number);
	(*stack)->n = number;
}
