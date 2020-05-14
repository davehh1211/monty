#include "monty.h"
/**
 * o_pop - deletes a value from the stack (linked list)
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_dlistint(*stack);
		fclose(var_global.file);
		free(var_global.buffer);
		exit(EXIT_FAILURE);
	}

	if (tmp->next != NULL) /*the fist one*/
	{
		*stack = tmp->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(tmp);
}
