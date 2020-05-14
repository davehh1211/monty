#include "monty.h"
/**
 * o_pall - print the stack from the beginning to the end
 * @stack: stack to be printed
 * @line_number: var not used.
 * Return: nothing
 */
void o_pall(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	stack_t *tmp = *stack;

	(void)line_number;

	for (i = 0; tmp != NULL; i++)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}

}
