#include "monty.h"

/**
 * main_monty - It's a Main Monty Function
 *@argc: It's an Argument Number
 *@argv: It's an Argument Vector
 *Return: (0) successful, Depend Condition
 */

int main_monty(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	int b;
	char *line = NULL;
	char *opcode = NULL;
	stack_t *stack = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;

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

	check(argc, argv, file);

	while (getline(&line, &line_length, file) != -1 && !feof(file))
	{
		opcode = strtok(line, " \n");

		if (opcode == NULL)
		{
			line_number++;
			continue;
		}

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

		line_number++;
	}

	free(line);
	frees_stack(stack);
	fclose(file);
	return (0);
}
