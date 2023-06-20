#include "monty.h"

/**
 * get_instruct_funct - select the correct function to execute
 * @opcode: the opcode passed as an argument
 * Return: a pointer to the function that corresponds to the opcode given
 * as a parameter
 */
void (*get_instruct_funct(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pal", pal},
		{"pint", pint}
	};

	while (i < 3)
	{
		if (_strcmp(opcode, insturct[i].opcode) == 0)
			return (instruct[i].f);
		i++;
	}
	return (NULL);
}		
