#include "monty.h"

/**
 * frees_stack - A function that Frees the stack
 *@head: A pointer to the top element of the stack Head.
 *Return: Void (0) successful
*/

void frees_stack(stack_t *head)
{
	stack_t *next_node;

	while (head != NULL)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}
