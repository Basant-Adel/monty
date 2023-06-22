#include "monty.h"

/**
 * swaps_stack - A function in the Monty language interpreter that swaps
 *the positions of the top two elements of the stack.
 *
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void swaps_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *number;
	int switch_node;
	number = *stack;

	if (number == NULL || number->next == NULL)
	/* It checks if the number is either empty or has only one element. */
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	switch_node = number->n;
	number->n = number->next->n;
	number->next->n = switch_node;
}
