#ifndef MONTY_H
#define MONTY_H


#define STACK 1
#define QUEUE 0
#define _GNU_SOURCE
#define UNUSED(x) (void)(x)
#define INSTRUCTIONS_COUNT 17


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
 * struct data_b - A function to hold the data for Monty
 *@line_number: The current line number being executed
 *@arg1: It's The first argument
 *@arg2: It's The second argument
 *@stack: It's a Pointer to the top of the stack
 *@file: It's a Pointer to the file being executed
 *@line: It's a Pointer to the current line being executed
 *@mode: It's The mode of the Monty (STACK || QUEUE)
 */
typedef struct data_b
{
	int line_number;
	char *arg1;
	char *arg2;
	stack_t *stack;
	FILE *file;
	char *line;
	int mode;
} data_n;

extern data_n data_here;


/**
 * struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* ERROR Prototypes */


void _usage_error(void);
void _malloc_error(void);
void _fopen_error(char *name_f);
void _add_error(int line_number);
void _sub_error(int line_number);
void _div_error(int line_number);
void _mul_error(int line_number);
void _mod_error(int line_number);
void _push_error(int line_number);
void _pint_error(int line_number);
void _swap_error(int line_number);
void _pchar_error(int line_number);
void _div_0_error(int line_number);
void stack_empty_error(int line_number);
void _pchar_empty_error(int line_number);
void inst_invalid_error(int line_number, char *inst_opcode);


/* Execute Prototypes */


int execute_file(char *name_f);
void execute_line(char *line, int line_number);


/* Instructions Prototypes */


void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);


/* The Linked List Prototypes */


void free_stack(stack_t *head);
void top_n_del(stack_t **stack);
size_t print_all(const stack_t *h);
stack_t *adds_node(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);


/* Helper Prototypes */


void all_free(void);
int is_number(char *str);
int is_empty_line(char *line);


#endif
