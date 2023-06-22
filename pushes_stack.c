#include "monty.h"

/**
 * push - A function that pushes an element to the top of a stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void push(stack_t **stack, unsigned int line_number)
{
	int number;
	char *arg;
	stack_t *new = malloc(sizeof(stack_t));

	arg = strtok(NULL, " ");

	if (arg == NULL)
	/* It checks If "arg" is indeed pointing to NULL */
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(arg);

	if (is_number(arg) == -1)
	/* To check If the return value of is_number() is really -1 or not */
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new == NULL)
	/* To check If new_node is indeed pointing to NULL */
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}
