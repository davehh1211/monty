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
	char *digit;
	int num;

	digit = strtok(NULL, "\t\n ");
	if (digit == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	num = atoi(digit);/*printf("%s\n", digit);*/
	newnode->n = num;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
