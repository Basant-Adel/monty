#include "monty.h"

/**
 * divides_stack - A function that divides the second element of the stack
 *by the top element of the stack.
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void divides_stack(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL || (*stack)->next == NULL)
	/* It checks if the stack is either empty or has only one element. */
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->next->n;

	if (number == 0)
	/* To check if the value of the variable number is equal to 0. */
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}

	number = number / (*stack)->n;
	pop_stack(stack, line_number);
	(*stack)->n = number;
}
