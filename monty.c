#include "monty.h"
free_t var_global;
/**
 * main - Monty interpreter language
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: 0 in success, 1 in failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileread(argv[1], &stack);

	free_dlistint(stack);

	exit(EXIT_SUCCESS);
}
/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * fileread - read the file
 * @argv: arguement to be opened
 * @stack: stack of numbers
 * Return: nothing
 */
void fileread(char *argv, stack_t **stack)
{
	unsigned int line_number = 0;
	char *opcode = NULL;
	size_t len = 0;

	var_global.file = fopen(argv, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&var_global.buffer, &len, var_global.file) != -1)
	{
		opcode = strtok(var_global.buffer, "\t\n ");
		line_number++;
		if (opcode != NULL && opcode[0] != '#')
			optacodevalid(opcode, line_number, stack);
	}
	free(var_global.buffer);
	fclose(var_global.file);
}
