#include "monty.h"
/**
 * main - 
 * @argc:
 * @argv:
 * Return: 
 */
int main(int argc, char *argv[])
{
	FILE *filename = NULL;
	unsigned int line_number = 1;
	char *buffer = NULL, *opcode = NULL, *num;
	size_t len = 0;
	/*stack_t **stack = NULL;*/

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	filename = fopen(argv[1], "r");
	if (filename == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &len, filename) != -1)
	{
		opcode = strtok(buffer, "\n\t ");
		num = strtok(NULL, "\n\t ");
		line_number++;
		/*printf("%s - %s\n", opcode, num);*/
		if (opcode != NULL)
			optacodevalid(opcode, num, line_number);
	}
	/*free(filename); This free is neccessary but it send us some errors*/
	free(buffer);
	exit(EXIT_SUCCESS);
}
