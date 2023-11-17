#include "monty.h"

bytecode_file_stat_t fstat = {true, false, 0, 0, 0, 0, 0};
/**
 * main - entry point of a monty bytecode interpreter
 * @ac: argument count
 * @av: argument list
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	size_t sz = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fstat.bytecodes = fopen(av[1], "r");
	if (!fstat.bytecodes)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&fstat.line, &sz, fstat.bytecodes) != -1)
	{
		fstat.line_num += 1;
		fstat.op_code = str_tok(fstat.line, " \t\n");
		fstat.op_code_arg = str_tok(NULL, " \t\n");
		if (fstat.op_code && (fstat.op_code[0] != '#'))
			exec_opcode(&stack);
		free(fstat.line);
		fstat.line = NULL;
		sz = 0;
	}
	fclose(fstat.bytecodes);
	free(fstat.line);
	free_stack_t(stack);
	return (0);
}
