#include "monty.h"
/**
 * 
 * 
 */
int main(int argc, char *argv[])
{
	FILE *filename = NULL;
	unsigned int line_number = 1, i = 0;
	char *buffer = NULL, *token = NULL, **arguments = NULL;
	size_t n = 0;
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
	while (getline(&buffer, &n, filename) != -1)
	{
		/* check if it need a buffer duplicated */
		arguments = malloc(3 * sizeof(char *));
		if (arguments == NULL)
				exit(EXIT_FAILURE);
		token = strtok(buffer, "\n\t ");
		while (token != NULL)
		{
			arguments[i] = malloc(sizeof(char));
			if (arguments[i] == NULL)
			{
				free(arguments);
				exit(EXIT_FAILURE);
			}
			strncpy(arguments[i], token, strlen(token) + 1);
			token = strtok(NULL, "\n\t ");
			i++;
		}
		arguments[i] = '\0';
		for (i = 0; arguments; i++)
			printf("%s\n", arguments[i]);
		for (i = 0; arguments; i++)
			free(arguments[i]);
		free(arguments);
		/*if (token != NULL)
		{
			optacodevalid(token, &stack, line_number);
		}*/
		line_number++;
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}

