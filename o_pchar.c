#include "monty.h"
/**
 * o_pchar - prints the char at the top of the stack
 * @stack: the stack to be deleted
 * @line_number: the line of the file read
 * Return: nothing
 */
void o_pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_dlistint(*stack);
		fclose(var_global.file);
		free(var_global.buffer);
		exit(EXIT_FAILURE);
	}
	/*if (((*stack)->n >= 65 && (*stack)->n <= 90) || ()*/
	if (isalpha((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		fclose(var_global.file);
		free(var_global.buffer);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
