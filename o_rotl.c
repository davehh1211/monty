#include "monty.h"
/**
 * o_rotl - rotates the stack to the top
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = *stack;

	(void)line_number;

	*stack = (*stack)->next;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	(*stack)->prev->next = NULL;
	tmp1->next = (*stack)->prev;
	(*stack)->prev->prev = tmp1;
	(*stack)->prev = NULL;
}
