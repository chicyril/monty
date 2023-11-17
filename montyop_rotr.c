#include "monty.h"

/**
 * _rotr_ - the last element of the stack becomes the stack
 * @stack: address of the stack pointer
 * @line_number: line number of the current executing opcode
**/
void _rotr_(stack_t **stack, unsigned int line_number)
{
	stack_t *be_top = NULL, *traverse = *stack;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	while (traverse->next->next)
		traverse = traverse->next;
	be_top = traverse->next;
	traverse->next = NULL;
	be_top->prev = NULL;
	be_top->next = *stack;
	*stack = be_top;
}
