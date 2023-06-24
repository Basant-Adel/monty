#include "monty.h"

/**
 * _rotl - A function in the Monty program that rotates the stack to the left
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _rotl(stack_t **stack, unsigned int line_number)
{

	int top_node = 0;
	stack_t *b = NULL;

	UNUSED(line_number);

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		top_node = (*stack)->n;
		b = *stack;

		while (b->next)
		{
			b->n = b->next->n;
			b = b->next;
		}

		b->n = top_node;

	}
}

/**
 * _rotr - A function in the Monty program that rotates the stack to the right
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	int last_node = 0;
	stack_t *b = NULL;

	UNUSED(line_number);

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{

		b = *stack;

		while (b->next != NULL)
		{
			last_node = b->n;
			b = b->next;
		}

		last_node = b->n;

		while (b->prev != NULL)
		{
			b->n = b->prev->n;
			b = b->prev;
		}

		(*stack)->n = last_node;

	}
}
