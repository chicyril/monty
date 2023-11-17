#include "monty.h"

/**
 * _push_ - push a value onto a stack
 * @stack: address of stack pointer
 * @line_number: line number of currently executing stack
 */
void _push_(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = NULL;


	if (!fstat.op_code_arg || !is_digs(fstat.op_code_arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(fstat.line);
		free_stack_t(*stack);


		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(fstat.line);
		free_stack_t(*stack);


		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	new_stack->n = atoi(fstat.op_code_arg);
	new_stack->prev = NULL;
	new_stack->next = *stack;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}
