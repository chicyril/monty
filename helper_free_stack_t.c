#include "monty.h"

/**
 * free_stack_t - free all allocations in a stack
 * @stack: the stack pointer
 */
void free_stack_t(stack_t *stack)
{
	stack_t *top = NULL;

	while (stack)
	{
		top = stack;
		stack = stack->next;
		free(top);
	}
}
