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
	int check_instruction = -1;
	char *arg;
	instruction_t command[] = {
		{"pop", pop_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{"pall", pall},
		{"mod", modulo_stack},
		{"swap", swaps_stack},
		{"pint", prints_stack},
		{"div", divides_stack},
		{"pchar", pchar_stack},
		{"push", push},
		{"rotl", rotates_stack},
		{"sub", subtracts_stack},
		{"mul", multiplies_stack},
		{"pstr", print_string_stack}
	};
	
	arg = strtok(opcode, " \n");

	if (arg[0] == '#')
	{
		nop_stack(&stack, line_number);
		return;
	}

	for (b = 0; b < INSTRUCTION_NUMS; b++)
	{
		if (strcmp(arg, command[b].opcode) == 0)
		{
			check_instruction = b;
			break;
		}
	}

	if (check_instruction == -1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	else
	{
		command[b].f(&stack, line_number);
	}
}
