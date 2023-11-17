#include "monty.h"

/**
 * _swap_ - swap the values on the first 2 stack
 * @stack: address of the stack pointer
 * @line_number: line number of the currently executing opcode
 */
void _swap_(stack_t **stack, unsigned int line_number)
{
	stack_t *go_under = NULL, *come_top = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(fstat.line);
		free_stack_t(*stack);

		fclose(fstat.bytecodes);
		exit(EXIT_FAILURE);
	}
	go_under = *stack;
	come_top = (*stack)->next;
	go_under->next = come_top->next;
	come_top->next = go_under;
	go_under->prev = come_top;
	come_top->prev = NULL;
	*stack = come_top;
}
