#include "monty.h"
/**
 * pop_stack - A function to Removes the top element of the stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *re_element;

	if (*stack == NULL)
	/*To check if the value of the pointer variable stack is pointing to NULL*/
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	re_element = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	/*To check if the value of pointer variable stack isn't pointing to NULL*/
	{
		(*stack)->prev = NULL;
	}
	free(re_element);
}
