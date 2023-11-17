#include "monty.h"

/**
 * _pop_ - pop the (delete) the top of the stack
 * @stack: address of the stack pointer
 * @line_number: line number of the current executing opcode
 */
void _pop_(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;


	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(fstat.line);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top);
}
