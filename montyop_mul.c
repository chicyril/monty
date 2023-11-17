#include "monty.h"

/**
 * _mul_ - divide second stack by top of stack
 * @stack: address of the stack pointer
 * @line_number: line number of executing opcode
 */
void _mul_(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(fstat.line);
		free_stack_t(*stack);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop_(stack, line_number);
}
