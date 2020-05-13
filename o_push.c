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
	int digit;

	digit = atoi(strtok(NULL, "\t\n\r "));
	if(digit == '\0')
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
	/*printf("%s\n", digit);*/
	newnode->n = digit;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
