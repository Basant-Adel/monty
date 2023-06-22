#include "monty.h"

/**
 * pall_stack - A function to Print all the values on the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void pall_stack(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *number;

	for (number = *stack; number != NULL; number = number->next)
	{
		printf("%d\n", number->n);
	}
}
