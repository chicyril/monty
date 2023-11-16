#include "monty.h"

/**
 * _pint_ - print the value on top of the stack
 * @stack: address of stack pointer
 * @line_number: line number of current executing code
 */
void _pint_(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(fstat.line);
		free_stack_t(*stack);


		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
