#include "monty.h"
/**
 * o_pstr - prints the string starting at the top of the stack
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c;

	(void)line_number;
	while (tmp)
	{
		c = tmp->n;		
		if (isascii(c) == 0 || c == 0)
			break;
		fprintf(stdout, "%c", c);	
		tmp = tmp->next;
	}
	putchar('\n');
}
