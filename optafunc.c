#include "monty.h"
/*
*
*
*/
void optacodevalid(char **token, stack_t **stack, unsigned int line_number )
{
instruction_t optaexist[] = {
		{"push", o_push},
		{"pall", o_pall},
		{"pint", o_pint},
		{"pop", o_pop},
		{"swap", o_swap},
		{"add", o_add},
		{"nop", o_nop},
		{"sub", o_sub},
		{"div", o_div},
		{"mul", o_mul},
		{"mod", o_mod},
		{"pchar", o_pchar},
		{NULL, NULL}
    };

for (i = 0; optaexist[i].opcode != NULL; i++)
{
	for (j = 0; token)
	if (token[i] == optaexist[i].opcode)
	{
		return (optaexit[i].(*f)( **stack, line_number);)
	}
}
if (! optaexist[i].opcode)
{
	dprintf(STDOUT_FILENO, "L%d: unknown instruction %s", line_number, token);
	exit(EXIT_FAILURE);
}

}