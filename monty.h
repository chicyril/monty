#ifndef _MONTY_H
#define _MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bytecode_file_stat - info stat for bytecode file
 * @stack: opcode processed in stack mode - default
 * @queue: opcode processed in queue mode
 * @line_num: line number currently being processed
 * @line: string content of the current line
 * @op_code: the opcode in the current line
 * @op_code_arg: the argument to the opcode
 * @bytecodes: opened bytecode file
 */
typedef struct bytecode_file_stat
{
	bool stack;
	bool queue;
	unsigned int line_num;
	char *line;
	char *op_code;
	char *op_code_arg;
	FILE *bytecodes;
} bytecode_file_stat_t;

extern bytecode_file_stat_t fstat;

bool is_digs(char *str);
bool isdelim(char c, const char *str);
char *mv_ptr(char *str, const char *delim);
char *str_tok(char *str, const char *delim);
void free_stack_t(stack_t *stack);
void exec_opcode(stack_t **stack);
void _push_(stack_t **stack, unsigned int line_number);
void _pall_(stack_t **stack, unsigned int line_number);
void _pint_(stack_t **stack, unsigned int line_number);
void _pop_(stack_t **stack, unsigned int line_number);
void _swap_(stack_t **stack, unsigned int line_number);
void _add_(stack_t **stack, unsigned int line_number);
void _nop_(stack_t **stack, unsigned int line_number);
void _sub_(stack_t **stack, unsigned int line_number);
void _div_(stack_t **stack, unsigned int line_number);
void _mul_(stack_t **stack, unsigned int line_number);
void _mod_(stack_t **stack, unsigned int line_number);
void _pchar_(stack_t **stack, unsigned int line_number);
void _pstr_(stack_t **stack, unsigned int line_number);
void _rotl_(stack_t **stack, unsigned int line_number);
void _rotr_(stack_t **stack, unsigned int line_number);

#endif
