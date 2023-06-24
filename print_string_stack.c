#include "monty.h"

/**
 * _pstr - A function to Print string starting at top of stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return : Void (0) successful
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *b;

	UNUSED(line_number);
	b = *stack;

	while (b)
	{
		if ((b->n >= 65 && b->n <= 90) || (b->n >= 97 && b->n <= 122))
		{
			printf("%c", b->n);
			b = b->next;
		}
		else
		{
			break;
		}
	}

	printf("\n");
}
