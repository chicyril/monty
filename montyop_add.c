#include "monty.h"

/**
 * _add_ - add the top value with the value under the top of stack
 * @stack: address of the stack pointer
 * @line_number: line number of the executing opcode
 */
void _add_(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		free(fstat.line);
		free_stack_t(*stack);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop_(stack, line_number);

}
