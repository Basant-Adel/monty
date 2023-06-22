#include "monty.h"

/**
 * pchar_stack - A function to Print the char at the top of the stack
 *@head: A pointer to the top element of the stack Head.
 *@counter: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void pchar_stack(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar_stack, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar_stack, value out of range\n", counter);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
}
