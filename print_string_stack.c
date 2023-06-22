#include "monty.h"

/**
 * print_string_stack -  A function to Print string starting at top of stack
 *@head: A pointer to the top element of the stack Head.
 *@counter: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void print_string_stack(stack_t **head, unsigned int counter)
{
	stack_t *top_element = *head;
	(void)counter;

	while (top_element != NULL)
	{
		if (top_element->n <= 0 || top_element->n > 127)
		{
			break;
		}

		printf("%c", top_element->n);
		top_element = top_element->next;
	}

	printf("\n");
}
