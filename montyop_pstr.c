#include "monty.h"

/**
 * _pstr_ - print string starting from the top of the stack
 * @stack: address of stack pointer
 * @line_number: line number
 */
void _pstr_(stack_t **stack, unsigned int line_number)
{
	stack_t *printer = NULL;
	(void)line_number;

	if (*stack)
	{
		printer = *stack;
		while (printer)
		{
			if (!(printer->n >= 32 && printer->n <= 126))
				break;
			putchar(printer->n);
			printer = printer->next;
		}
	}
	putchar('\n');
}
