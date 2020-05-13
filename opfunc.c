#include "monty.h"
/*
*
*
*/
void optacodevalid(char *opcode, unsigned int line_number)
{
	stack_t **stack = NULL;
	int i = 0, flag = 0;
	instruction_t opexist[] = {
			{"push", o_push},
			{"pall", o_pall},
			/*{"pint", o_pint},
			{"pop", o_pop},
			{"swap", o_swap},
			{"add", o_add},
			{"nop", o_nop},
			{"sub", o_sub},
			{"div", o_div},
			{"mul", o_mul},
			{"mod", o_mod},
			{"pchar", o_pchar},*/
			{NULL, NULL}
		};

	for (i = 0; opexist[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opexist[i].opcode) == 0)
		{
			opexist[i].f(stack, line_number);
			flag++;
		}
	}
	if (flag == 0)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode); /*<> */
		exit(EXIT_FAILURE);
	}
}
