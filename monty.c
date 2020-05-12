#include "montyheader.h"
/**
 * 
 * 
 */
int main(int argc, char *argv[])
{
	FILE *filename = NULL;
	int i;
	char *buffer = NULL, *token = NULL;
	size_t n = 0;
	stack_t **stack = NULL;


	if (argc != 2)
	{
		dprintf(STOUT_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	filename = fopen(argv[1], "r");
	if (filename == NULL)
	{
		dprintf(STOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	i = getline(&buffer, &n, filename);
	if (i < 0)
		free(buffer);
	token = parse_buffer(buffer) /*COMO PARSEAMOS*/
	/*strtok(buffer, "\n\t\r ");*/
	if (token != NULL)
	{
		optacodevalid(token, &stack, line_number ));
	}
	exit(EXIT_SUCCESS);
}