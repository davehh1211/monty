#include "monty.h"
/**
 * main - Monty interpreter language
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: 
 */

int num = 0;

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
		if (atoi(strtok(NULL, "\t\n ")) < 0)
			num = -1 * atoi(strtok(NULL, "\t\n "));
		else if (atoi(strtok(NULL, "\t\n ")) >= 0)
			num = atoi(strtok(NULL, "\t\n "));
		else
			num = -1;
		line_number++;
		printf("%d", num);
		if (opcode != NULL)
			opcodevalid(opcode, line_number, &stack); /**/
	}
	/*free(file); This free is neccessary but it send us some errors*/
	free(buffer);
	exit(EXIT_SUCCESS);
}
