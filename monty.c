#include "monty.h"
/**
 * main - Monty interpreter language
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: 0 in success, 1 in failure
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	unsigned int line_number = 0;
	char *buffer = NULL, *opcode = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &len, file) != -1)
	{
		opcode = strtok(buffer, "\t\n ");
		line_number++;
		if (opcode != NULL)
			optacodevalid(opcode, line_number, &stack); /**/
	}
	/*free(file); This free is neccessary but it send us some errors*/
	free(buffer);
	exit(EXIT_SUCCESS);
}
