#include "monty.h"

/**
 * _pchar_ - print the value on top of the stack
 * @stack: address of stack pointer
 * @line_number: line number of current executing code
 */
void _pchar_(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(fstat.line);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->n >= 32 && (*stack)->n <= 126))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free(fstat.line);
		free_stack_t(*stack);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
