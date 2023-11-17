#include "monty.h"

/**
 * exec_opcode - match and execute opcode function
 * @stack: address of stack pointer
 */

void exec_opcode(stack_t **stack)
{
	int i = 0;
	instruction_t opcode_funcs[] = {
		{"push", _push_}, {"pall", _pall_}, {"pint", _pint_},
		{"pop", _pop_}, {"swap", _swap_}, {"add", _add_},
		{"nop", _nop_}, {"sub", _sub_}, {"div", _div_},
		{"mul", _mul_}, {"mod", _mod_}, {"pchar", _pchar_},
		{"pstr", _pstr_}, {"rotl", _rotl_}, {"rotr", _rotr_},
		{NULL, NULL}
	};

	if (strcmp(fstat.op_code, "stack") == 0)
	{
		fstat.stack = true;
		fstat.queue = false;
		return;
	}
	if (strcmp(fstat.op_code, "queue") == 0)
	{
		fstat.stack = false;
		fstat.queue = true;
		return;
	}
	for (; opcode_funcs[i].opcode; i++)
	{
		if (strcmp(opcode_funcs[i].opcode, fstat.op_code) == 0)
		{
			opcode_funcs[i].f(stack, fstat.line_num);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",
			fstat.line_num, fstat.op_code);
	free(fstat.line);
	free_stack_t(*stack);

	fclose(fstat.bytecodes);
	exit(EXIT_FAILURE);
}
