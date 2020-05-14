#include "monty.h"
/**
 * o_push - enter a value to the stack (linked list)
 * @stack: the stack to be added
 * @line_number: the line of the file read
 * Return: nothing
 */

void o_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	if (num == -1)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	/*printf("%d\n", num);*/
	newnode->n = num;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
