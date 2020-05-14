#include "monty.h"
/*
* optacodevalid - dictionary of opcodes.
* @opcode: string to compare
* @stack: list to evaluate
* @line_number: number of line of command
* Return: nothing
*/
void optacodevalid(char *opcode, unsigned int line_number,
stack_t **stack)
{
	int i = 0, flag = 0;
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
			{"pstr", o_pstr},
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
		fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, opcode);
		free(var_global.buffer);
		free_dlistint(*stack);
		fclose(var_global.file);
		exit(EXIT_FAILURE);
	}
}
