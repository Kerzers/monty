#include "monty.h"

char *instruct[SIZE];
/**
 *
 *
 *
 *
 */
int main(int ac, char **av)
{
	FILE *file;
	char line[1024], **instruct;
	size_t len = 1024;
	unsigned int count = 0;
	stack_t *stack = NULL;
	void (*func)(stack_t **, unsigned int);

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while(fgets(line, len, file) != NULL)
	{
		count++;
		if (strcmp("\n", line) == 0)
			continue;
		instruct = tokenize(line);
		if (!instruct)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", count, instruct[0]);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	
		func = get_instruct_funct(instruct[0]);
		if (func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", count, instruct[0]);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		
		func(&stack, count);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}


/**
 *
 *
 *
 */
char **tokenize(char *line)
{
	char *delim = " \t\n";

	instruct[0] = strtok(line, delim);
	if (!instruct[0])
		return (NULL);
	if (strcmp("push", instruct[0]) == 0)
		instruct[1] = strtok(NULL, delim);
	return (instruct);
}
