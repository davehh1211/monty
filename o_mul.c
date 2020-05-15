#include "monty.h"
/**
 * o_mul - multiplies the top two elements of the stack
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(*stack);
		fclose(var_global.file);
		free(var_global.buffer);
		exit(EXIT_FAILURE);
	}
	tmp->next->n *= tmp->n;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}
