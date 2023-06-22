#include "monty.h"

/**
 * pall - A function to Prints all the values on the stack (pall_stack)
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *number;

	UNUSED(line_number);
	/* stack_t *number; */

	for (number = *stack; number != NULL; number = number->next)
	{
		printf("%d\n", number->n);
	}
}
