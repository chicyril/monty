#include "monty.h"

/**
 * _push_ - push a value onto a stack
 * @stack: address of stack pointer
 * @line_number: line number of currently executing stack
 */
void _push_(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (!fstat.op_code_arg || !is_digs(fstat.op_code_arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(fstat.line);
		free_stack_t(*stack);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(fstat.line);
		free_stack_t(*stack);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	top->n = atoi(fstat.op_code_arg);
	top->prev = NULL;
	top->next = *stack;
	if (*stack)
		(*stack)->prev = top;
	*stack = top;
	if (fstat.queue)
		_rotl_(stack, line_number);
}
