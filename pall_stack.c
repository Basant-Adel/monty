#include "monty.h"

/**
 * pall - A function to Prints all the values on the stack (pall_stack)
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *number = *stack;

	UNUSED(line_number);
	/* stack_t *number; */

	while (number)
	{
		printf("%d\n", number->n);
		number = number->next;
	}
}
