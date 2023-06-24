#include "monty.h"

/**
 * execute_file - A function that Executes the file
 *@file_name: It's a file name
 *Return: (0) successful
*/

int execute_file(char *file_name)
{
	FILE *file = fopen(file_name, "r");
	char *line = NULL;
	size_t line_length = 0;
	stack_t *stack = NULL;
	char *opcode = NULL;
	unsigned int line_number = 1;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	/*Read and execute each line until the end of the file*/
	while (getline(&line, &line_length, file) != -1 && !feof(file))
	{
		opcode = strtok(line, " \n");
		if (opcode == NULL)
		{
			line_number++;
			continue;
		}
		execute_opcode(line, stack, line_number);
		line_number++;
	}
	frees_stack(stack);
	fclose(file);
	free(line);
	return (0);
}

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
	char *arg = strtok(opcode, " \n");
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
		command[b].f(&stack, line_number);
}
