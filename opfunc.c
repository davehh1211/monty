#include "monty.h"
/*
* optacodevalid - dictionary of opcodes.
* @opcode: string to compare
* @stack: list to evaluate
* @line_number: number of line of command
* Return: nothing
*/
void opcodevalid(char *opcode, unsigned int line_number, stack_t **stack)
{
	int i = 0, flag = 0;
	instruction_t opexist[] = {
			{"push", o_push},
			{"pall", o_pall},
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
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
		line_number, opcode); /*<> */
		exit(EXIT_FAILURE);
	}
}
