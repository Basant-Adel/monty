#include "monty.h"

/**
 * subtracts_stack - A function that subtracts the top
 *and second top elements of stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void subtracts_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *number;
	int subtract;

	number = *stack;

	if (number == NULL || number->next == NULL)
	/* It checks if the number is either empty or has only one element. */
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	subtract = number->next->n - number->n;
	number->next->n = subtract;
	pop_stack(stack, line_number);
}
