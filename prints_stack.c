#include "monty.h"

/**
 * prints_stack - A function that prints the value at the top of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void prints_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *number;

	number = *stack;

	if (number == NULL)
	/*To check if the value of the pointer variable number is pointing to NULL*/
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", number->n);
}
