#include "monty.h"

/**
 * rotates_stack - A function to Rotate the stack to the top
 *@head: A pointer to the top element of the stack Head.
 *@counter: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void rotates_stack(stack_t **head, unsigned int counter)
{
	stack_t *top_element = *head;
	int n;

	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
	/* It checks if the stack is either empty or has only one element. */
	{
		return ();
	}

	n = (*head)->n;

	while (top_element->next != NULL)
	{
		top_element->n = top_element->next->n;
		top_element = top_element->next;
	}

	top_element->n = n;
}
