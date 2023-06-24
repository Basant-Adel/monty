#include "monty.h"

/**
 * print_all - A function to print all the elements
 *@head: It's a pointer to stack_t
 *Return: The Number of NODE
 */

size_t print_all(const stack_t *head)
{
	int b = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		b++;
	}

	return (b);

}

/**
 * adds_node - A function that adds a new node
 *at the beginning of a doubly linked list
 *
 *@head: It's a Pointer to the head
 *@n: It's a Value
 *Return: (Pointer)-> new node or (NULL)-> failure
 */

stack_t *adds_node(stack_t **head, const int n)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));

	if (n_node == NULL)
	{
		return (NULL);
	}

	n_node->n = n;
	n_node->next = NULL;
	n_node->prev = NULL;

	if (*head)
	{
		(*head)->prev = n_node;
		n_node->next = *head;
	}

	*head = n_node;

	return (n_node);
}

/**
 * add_node_end - A function that add new node at the end
 * @head: It's a pointer to head
 * @n: It's an integer value
 * Return: The Node Address or (NULL) Fail
 */

stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *n_node, *current_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		return (NULL);
	}
	n_node->n = n;
	n_node->next = NULL;
	n_node->prev = NULL;

	if (*head == NULL)
	{
		*head = n_node;
	}
	else
	{
		current_node = *head;
	}

	while (current_node->next)
	{
		current_node = current_node->next;

		n_node->prev = current_node;
		current_node->next = n_node;
	}
	return (n_node);
}

/**
 * free_stack - A function to free all the elements
 *@head: It's a pointer
 *Return: Nothing (void)
 */

void free_stack(stack_t *head)
{
	stack_t *current_node;

	current_node = head;

	while (head)
	{
		current_node = head;
		head = head->next;

		if (current_node)
		{
			free(current_node);
		}
	}
}

/**
 * top_n_del - A function to free all the elements
 *@stack: It's a pointer
 *Return: Nothing (void)
 */

void top_n_del(stack_t **stack)
{
	stack_t *n_top;

	if (*stack == NULL)
	{
		printf("Error: Stack is empty.\n");
		return;
	}

	n_top = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	n_top->next = NULL;
	free(n_top);
}
