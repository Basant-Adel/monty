#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define UNUSED(x) (void)(x)
#define INSTRUCTION_NUMS 14
#define STACK 1
#define QUEUE 0
#define BUFFER_SIZE 1000
/* #define INSTRUCTIONS_COUNT 14 */

/* The C Standard Library */

#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>

/* Data structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* The prototypes of all your functions */

int main(int argc, char *argv[]);
int is_number(char *argument);
void frees_stack(stack_t *stack);
void pchar_stack(stack_t **head, unsigned int counter);
void rotates_stack(stack_t **head, unsigned int counter);
void check_arguments(int argc, char *argv[], FILE *file);
void add_stack(stack_t **stack, unsigned int line_number);
void nop_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void swaps_stack(stack_t **stack, unsigned int line_number);
void modulo_stack(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void prints_stack(stack_t **stack, unsigned int line_number);
void print_string_stack(stack_t **head, unsigned int counter);
void divides_stack(stack_t **stack, unsigned int line_number);
void subtracts_stack(stack_t **stack, unsigned int line_number);
void multiplies_stack(stack_t **stack, unsigned int line_number);
void execute_opcode(char *opcode, stack_t *stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
