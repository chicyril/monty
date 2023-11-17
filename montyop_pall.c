#include "monty.h"

/**
 * _pall_ - print all the vallues in a stack
 * @stack: address of stack pointer
 * @line_number: line number of the executing code
 */
void _pall_(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	(void)line_number;

	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
