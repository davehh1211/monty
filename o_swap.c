#include "monty.h"
/**
 * o_swap - swaps the top two elements of the stack.
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int i = 0;

	if (stack == NULL || *stack == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		fclose(var_global.file);
		free(var_global.buffer);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	(*stack)->n = tmp->next->n;
	tmp->next->n = i;
}
