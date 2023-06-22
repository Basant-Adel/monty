#include "monty.h"

/**
 * execute_opcode - A function that Executes the opcode
 *@opcode: It's a parameter that represents operation code in Monty language
 *@stack: A pointer to the top element of the stack
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void execute_opcode(char *opcode, stack_t *stack, unsigned int line_number)
{
	int b;

	instruction_t command[] = {
		{NULL, NULL},
		{"pop", pop_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{"pall", pall_stack},
		{"mod", modulo_stack},
		{"swap", swaps_stack},
		{"pint", prints_stack},
		{"div", divides_stack},
		{"pchar", pchar_stack},
		{"push", pushes_stack},
		{"rotl", rotates_stack},
		{"sub", subtracts_stack},
		{"mul", multiplies_stack},
		{"pstr", print_string_stack}
	};

	for (b = 0; command[b].opcode != NULL; b++)
	{
		if (strcmp(opcode, command[b].opcode) == 0)
		{
			command[b].f(&stack, line_number);
			break;
		}
	}

	if (command[b].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
