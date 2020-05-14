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
	if (digit == NULL || numberchecker(digit))
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
/**
 * numberchecker - checks if the string is a digit
 * @str: string to be checked
 * Return: 
 */
int numberchecker(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			i++;
			continue;
		}
		if (isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
