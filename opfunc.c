#include "monty.h"
/*
*
*
*/
void optacodevalid(char *opcode, char *num, unsigned int line_number)
{
	stack_t **stack;
	instruction_t opexist[] = {
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

	for (i = 0; opexist[i].opcode != NULL; i++)
	{
		if (opcode == opexist[i].opcode)
		{
			stack->n = atoi(num);
			return (opexit[i].(*f)(stack, line_number))
		}
	}
	dprintf(STDOUT_FILENO, "L%d: unknown instruction %s", line_number, opcode);/* <> */
	exit(EXIT_FAILURE);
}