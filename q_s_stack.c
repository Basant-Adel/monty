#include "monty.h"

/**
 * _queue - A function that sets the mode of the program to "Queue"
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	data_here.mode = QUEUE;
}

/**
 * _stack - A function that sets the mode of the program to "Stack"
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	data_here.mode = STACK;
}
