#include "monty.h"
/**
 * o_rotr - rotates the stack to the bottom
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = *stack;

	(void)line_number;

	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	tmp1->prev = *stack;
	(*stack)->next = tmp1;
}
