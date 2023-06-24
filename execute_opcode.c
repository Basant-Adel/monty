#include "monty.h"

/**
 * execute_file - A function that Executes the file
 *@name_f: Name of the file containing the operations
 *Return: (0)-> Successful (-1)-> Failure
 */

int execute_file(char *name_f)
{
	FILE *the_file = fopen(name_f, "r");
	char *the_line = NULL;
	size_t _length_line = 0;
	ssize_t read_line;

	if (the_file == NULL)
	{
		_fopen_error(name_f);
	}

	data_here.file = the_file;

	while ((read_line = getline(&the_line, &_length_line, the_file)) != -1)
	{
		data_here.line_number++;
		data_here.line = the_line;
		if (is_empty_line(data_here.line) == 1)
		{
			execute_line(data_here.line, data_here.line_number);
		}
	}
	free_stack(data_here.stack);
	fclose(the_file);
	free(the_line);
	return (0);
}

/**
 * execute_line - A function that Executes the operation in single line
 *@line: Line of operation
 *@line_number: It's a parameter that represents the line number
 *Return: Void (0) successful
*/

void execute_line(char *line, int line_number)
{
	int b;
	int is_inst = -1;
	instruction_t instructions[] = {
		{"push", _push},
		{"pop", _pop}, {"mod", _mod},
		{"pall", _pall},
		{"pint", _pint}, {"swap", _swap},
		{"nop", _nop}, {"add", _add},
		{"sub", _sub}, {"mul", _mul},
		{"div", _div}, {"mul", _mul},
		{"pchar", _pchar}, {"queue", _queue},
		{"pstr", _pstr}, {"stack", _stack},
		{"rotl", _rotl}, {"rotr", _rotr},
	};
	data_here.arg1 = strtok(line, " \n");
	data_here.arg2 = strtok(NULL, " \n");
	if (data_here.arg1[0] == '#')
	{
		_nop(&data_here.stack, line_number);
		return;
	}
	for (b = 0; b < INSTRUCTIONS_COUNT; b++)
	{
		if (strcmp(data_here.arg1, instructions[b].opcode) == 0)
		{
			is_inst = b;
			break;
		}
	}

	if (is_inst != -1)
	{
		instructions[b].f(&data_here.stack, line_number);
	}
	else
	{
		inst_invalid_error(line_number, data_here.arg1);
	}
}

/**
 * is_empty_line - A function that Check if the Line is empty or not
 *@line: It's a Line to check if it empty or not
 *Return: (1)-> The line is empty (0)-> Otherwise
 */

int is_empty_line(char *line)
{
	int b;
	int length_of_line = strlen(line);

	if (length_of_line > 0)
	{
		if (line[length_of_line - 1] == '\n')
		{
			for (b = 0; b < length_of_line - 1; b++)
			{
				if (line[b] != ' ')
				{
					return (1);
				}
			}
			return (0);
		}
	}
	return (0);
}
