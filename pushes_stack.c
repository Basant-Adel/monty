#include "monty.h"

/**
 * _push - A function that pushes an element to the top of a stack
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _push(stack_t **stack, unsigned int line_number)
{
	int number = 0;

	if (data_here.arg2)
	{
		if (is_number(data_here.arg2))
		{
			number = atoi(data_here.arg2);

			if (data_here.mode == STACK)
			{
				adds_node(stack, number);
			}
			else
			{
				add_node_end(stack, number);
			}
		}
		else
		{
			_push_error(line_number);
		}
	}
	else
	{
		_push_error(line_number);
	}
}

/**
 * _push_error - A function to Print Push ERROR to element
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void _push_error(int line_number)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	all_free();
	exit(EXIT_FAILURE);

}

/**
 * all_free - A function to FREE ALL elements
 *Return: Void (0) successful
*/

void all_free(void)
{

	free_stack(data_here.stack);
	fclose(data_here.file);
	free(data_here.line);

}
