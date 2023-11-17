#include "monty.h"

/**
 * _rotl_ - the top element of a stack becomes the last
 * @stack: address of the stack pointer
 * @line_number: line number of the executing lopcode
 */
void _rotl_(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack, *go_last = *stack;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	while (traverse->next)
		traverse = traverse->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	traverse->next = go_last;
	go_last->prev = traverse;
	go_last->next = NULL;
}
