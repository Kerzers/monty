#include "monty.h"

/**
 * get_instruct_funct - select the correct function to execute
 * @opcode: the opcode passed as an argument
 * Return: a pointer to the function that corresponds to the opcode given
 * as a parameter
 */
void (*get_instruct_funct(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t opcode_instruct[] = {
		{"push", push},
		{"pall", pal},
		{"pint", pint}
	};

	while (i < 3)
	{
		if (strcmp(opcode, opcode_instruct[i].opcode) == 0)
			return (opcode_instruct[i].f);
		i++;
	}
	return (NULL);
}

/**
 * free_stack - free a double link list
 * @stack: the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;
	
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
